/*
 * Copyright 2015 Rockchip Electronics Co. LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __MPP_BUFFER_H__
#define __MPP_BUFFER_H__

#include "mpp_err.h"
#include "rk_type.h"

/*
 * MppBuffer module has several functions:
 *
 * 1. buffer get / put / reference management / external commit / get info.
 *    this part is the basic user interface for MppBuffer.
 *
 *    function:
 *
 *    mpp_buffer_get
 *    mpp_buffer_put
 *    mpp_buffer_inc_ref
 *    mpp_buffer_commit
 *    mpp_buffer_info_get
 *
 * 2. user buffer working flow control abstraction.
 *    buffer should attach to certain group, and buffer mode control the buffer
 * usage flow. this part is also a part of user interface.
 *
 *    function:
 *
 *    mpp_buffer_group_get
 *    mpp_buffer_group_normal_get
 *    mpp_buffer_group_limit_get
 *    mpp_buffer_group_put
 *    mpp_buffer_group_limit_config
 *
 * 3. buffer allocator management
 *    this part is for allocator on different os, it does not have user
 * interface it will support normal buffer, Android ion buffer, Linux v4l2 vb2
 * buffer user can only use MppBufferType to choose.
 *
 */

/*
 * mpp buffer group support two work flow mode:
 *
 * normal flow: all buffer are generated by MPP
 *              under this mode, buffer pool is maintained internally
 *
 *              typical call flow:
 *
 *              mpp_buffer_group_get()          return A
 *              mpp_buffer_get(A)               return a    ref +1 -> used
 *              mpp_buffer_inc_ref(a)                       ref +1
 *              mpp_buffer_put(a)                           ref -1
 *              mpp_buffer_put(a)                           ref -1 -> unused
 *              mpp_buffer_group_put(A)
 *
 * commit flow: all buffer are commited out of MPP
 *              under this mode, buffers is commit by external api.
 *              normally MPP only use it but not generate it.
 *
 *              typical call flow:
 *
 *              ==== external allocator ====
 *              mpp_buffer_group_get()          return A
 *              mpp_buffer_commit(A, x)
 *              mpp_buffer_commit(A, y)
 *
 *              ======= internal user ======
 *              mpp_buffer_get(A)               return a
 *              mpp_buffer_get(A)               return b
 *              mpp_buffer_put(a)
 *              mpp_buffer_put(b)
 *
 *              ==== external allocator ====
 *              mpp_buffer_group_put(A)
 *
 *              NOTE: commit interface required group handle to record group
 * information
 */

/*
 * mpp buffer group has two buffer limit mode: normal and limit
 *
 * normal mode: allows any buffer size and always general new buffer is no
 * unused buffer is available. This mode normally use with normal flow and is
 * used for table / stream buffer
 *
 * limit mode : restrict the buffer's size and count in the buffer group. if try
 * to calloc buffer with different size or extra count it will fail. This mode
 * normally use with commit flow and is used for frame buffer
 */

/*
 * NOTE: normal mode is recommanded to work with normal flow, working with limit
 * mode is not. limit  mode is recommanded to work with commit flow, working
 * with normal mode is not.
 */
typedef enum {
  MPP_BUFFER_INTERNAL,
  MPP_BUFFER_EXTERNAL,
  MPP_BUFFER_MODE_BUTT,
} MppBufferMode;

/*
 * the mpp buffer has serval types:
 *
 * normal   : normal malloc buffer for unit test or hardware simulation
 * ion      : use ion device under Android/Linux, MppBuffer will encapsulte ion
 * file handle ext_dma  : the DMABUF(DMA buffers) come from the application drm
 * : use the drm device interface for memory management
 */
typedef enum {
  MPP_BUFFER_TYPE_NORMAL,
  MPP_BUFFER_TYPE_ION,
  MPP_BUFFER_TYPE_EXT_DMA,
  MPP_BUFFER_TYPE_DRM,
  MPP_BUFFER_TYPE_DMA_HEAP,
  MPP_BUFFER_TYPE_BUTT,
} MppBufferType;

#define MPP_BUFFER_TYPE_MASK 0x0000FFFF

/*
 * MPP_BUFFER_FLAGS cooperate with MppBufferType
 * 16 high bits of MppBufferType are used in flags
 *
 * eg:
 * DRM CMA buffer : MPP_BUFFER_TYPE_DRM | MPP_BUFFER_FLAGS_CONTIG
 *                  = 0x00010003
 * DRM SECURE buffer: MPP_BUFFER_TYPE_DRM | MPP_BUFFER_FLAGS_SECURE
 *                  = 0x00080003
 *
 * flags originate from drm_rockchip_gem_mem_type
 */

#define MPP_BUFFER_FLAGS_MASK 0x000f0000     // ROCKCHIP_BO_MASK << 16
#define MPP_BUFFER_FLAGS_CONTIG 0x00010000   // ROCKCHIP_BO_CONTIG << 16
#define MPP_BUFFER_FLAGS_CACHABLE 0x00020000 // ROCKCHIP_BO_CACHABLE << 16
#define MPP_BUFFER_FLAGS_WC 0x00040000       // ROCKCHIP_BO_WC << 16
#define MPP_BUFFER_FLAGS_SECURE 0x00080000   // ROCKCHIP_BO_SECURE << 16

/*
 * MppBufferInfo variable's meaning is different in different MppBufferType
 *
 * Common
 * index - the buffer index used to track buffer in buffer pool
 * size  - the buffer size
 *
 * MPP_BUFFER_TYPE_NORMAL
 *
 * ptr  - virtual address of normal malloced buffer
 * fd   - unused and set to -1, the allocator would return its
 *         internal buffer counter number
 *
 * MPP_BUFFER_TYPE_ION
 *
 * ptr  - virtual address of ion buffer in user space
 * hnd  - ion handle in user space
 * fd   - ion buffer file handle for map / unmap
 *
 */
typedef struct MppBufferInfo_t {
  MppBufferType type;
  size_t size;
  void *ptr;
  void *hnd;
  int fd;
  int index;
} MppBufferInfo;

#define BUFFER_GROUP_SIZE_DEFAULT (SZ_1M * 80)

/*
 * mpp_buffer_import_with_tag(MppBufferGroup group, MppBufferInfo *info,
 * MppBuffer *buffer)
 *
 * 1. group - specified the MppBuffer to be attached to.
 *    group can be NULL then this buffer will attached to default legecy group
 *    Default to NULL on mpp_buffer_import case
 *
 * 2. info  - input information for the output MppBuffer
 *    info can NOT be NULL. It must contain at least one of ptr/fd.
 *
 * 3. buffer - generated MppBuffer from MppBufferInfo.
 *    buffer can be NULL then the buffer is commit to group with unused status.
 *    Otherwise generated buffer will be directly got and ref_count increased.
 *    Default to NULL on mpp_buffer_commit case
 *
 * mpp_buffer_commit usage:
 *
 * Add a external buffer info to group. This buffer will be on unused status.
 * Typical usage is on Android. MediaPlayer gralloc Graphic buffer then commit
 * these buffer to decoder's buffer group. Then decoder will recycle these
 * buffer and return buffer reference to MediaPlayer for display.
 *
 * mpp_buffer_import usage:
 *
 * Transfer a external buffer info to MppBuffer but it is not expected to
 * attached to certain buffer group. So the group is set to NULL. Then this
 * buffer can be used for MppFrame/MppPacket. Typical usage is for image
 * processing. Image processing normally will be a oneshot operation It does not
 * need complicated group management. But in other hand mpp still need to know
 * the imported buffer is leak or not and trace its usage inside mpp process. So
 * we attach this kind of buffer to default misc buffer group for management.
 */
#define mpp_buffer_commit(group, info)                                         \
  mpp_buffer_import_with_tag(group, info, NULL, MODULE_TAG, __FUNCTION__)

#define mpp_buffer_import(buffer, info)                                        \
  mpp_buffer_import_with_tag(NULL, info, buffer, MODULE_TAG, __FUNCTION__)

#define mpp_buffer_get(group, buffer, size)                                    \
  mpp_buffer_get_with_tag(group, buffer, size, MODULE_TAG, __FUNCTION__)

#define mpp_buffer_put(buffer) mpp_buffer_put_with_caller(buffer, __FUNCTION__)

#define mpp_buffer_inc_ref(buffer)                                             \
  mpp_buffer_inc_ref_with_caller(buffer, __FUNCTION__)

#define mpp_buffer_info_get(buffer, info)                                      \
  mpp_buffer_info_get_with_caller(buffer, info, __FUNCTION__)

#define mpp_buffer_read(buffer, offset, data, size)                            \
  mpp_buffer_read_with_caller(buffer, offset, data, size, __FUNCTION__)

#define mpp_buffer_write(buffer, offset, data, size)                           \
  mpp_buffer_write_with_caller(buffer, offset, data, size, __FUNCTION__)

#define mpp_buffer_get_ptr(buffer)                                             \
  mpp_buffer_get_ptr_with_caller(buffer, __FUNCTION__)

#define mpp_buffer_get_fd(buffer)                                              \
  mpp_buffer_get_fd_with_caller(buffer, __FUNCTION__)

#define mpp_buffer_get_size(buffer)                                            \
  mpp_buffer_get_size_with_caller(buffer, __FUNCTION__)

#define mpp_buffer_get_index(buffer)                                           \
  mpp_buffer_get_index_with_caller(buffer, __FUNCTION__)

#define mpp_buffer_set_index(buffer, index)                                    \
  mpp_buffer_set_index_with_caller(buffer, index, __FUNCTION__)

#define mpp_buffer_get_offset(buffer)                                          \
  mpp_buffer_get_offset_with_caller(buffer, __FUNCTION__)

#define mpp_buffer_set_offset(buffer, offset)                                  \
  mpp_buffer_set_offset_with_caller(buffer, offset, __FUNCTION__)

#define mpp_buffer_group_get_internal(group, type, ...)                        \
  mpp_buffer_group_get(group, type, MPP_BUFFER_INTERNAL, MODULE_TAG,           \
                       __FUNCTION__)

#define mpp_buffer_group_get_external(group, type, ...)                        \
  mpp_buffer_group_get(group, type, MPP_BUFFER_EXTERNAL, MODULE_TAG,           \
                       __FUNCTION__)

#ifdef __cplusplus
extern "C" {
#endif

/*
 * MppBuffer interface
 * these interface will change value of group and buffer so before calling
 * functions parameter need to be checked.
 *
 * IMPORTANT:
 * mpp_buffer_import_with_tag - compounded interface for commit and import
 *
 */
MPP_RET mpp_buffer_import_with_tag(MppBufferGroup group, MppBufferInfo *info,
                                   MppBuffer *buffer, const char *tag,
                                   const char *caller);
MPP_RET mpp_buffer_get_with_tag(MppBufferGroup group, MppBuffer *buffer,
                                size_t size, const char *tag,
                                const char *caller);
MPP_RET mpp_buffer_put_with_caller(MppBuffer buffer, const char *caller);
MPP_RET mpp_buffer_inc_ref_with_caller(MppBuffer buffer, const char *caller);

MPP_RET mpp_buffer_info_get_with_caller(MppBuffer buffer, MppBufferInfo *info,
                                        const char *caller);
MPP_RET mpp_buffer_read_with_caller(MppBuffer buffer, size_t offset, void *data,
                                    size_t size, const char *caller);
MPP_RET mpp_buffer_write_with_caller(MppBuffer buffer, size_t offset,
                                     void *data, size_t size,
                                     const char *caller);
void *mpp_buffer_get_ptr_with_caller(MppBuffer buffer, const char *caller);
int mpp_buffer_get_fd_with_caller(MppBuffer buffer, const char *caller);
size_t mpp_buffer_get_size_with_caller(MppBuffer buffer, const char *caller);
int mpp_buffer_get_index_with_caller(MppBuffer buffer, const char *caller);
MPP_RET mpp_buffer_set_index_with_caller(MppBuffer buffer, int index,
                                         const char *caller);
size_t mpp_buffer_get_offset_with_caller(MppBuffer buffer, const char *caller);
MPP_RET mpp_buffer_set_offset_with_caller(MppBuffer buffer, size_t offset,
                                          const char *caller);

MPP_RET mpp_buffer_group_get(MppBufferGroup *group, MppBufferType type,
                             MppBufferMode mode, const char *tag,
                             const char *caller);
MPP_RET mpp_buffer_group_put(MppBufferGroup group);
MPP_RET mpp_buffer_group_clear(MppBufferGroup group);
RK_S32 mpp_buffer_group_unused(MppBufferGroup group);
size_t mpp_buffer_group_usage(MppBufferGroup group);
MppBufferMode mpp_buffer_group_mode(MppBufferGroup group);
MppBufferType mpp_buffer_group_type(MppBufferGroup group);

/*
 * size  : 0 - no limit, other - max buffer size
 * count : 0 - no limit, other - max buffer count
 */
MPP_RET mpp_buffer_group_limit_config(MppBufferGroup group, size_t size,
                                      RK_S32 count);

RK_U32 mpp_buffer_total_now();
RK_U32 mpp_buffer_total_max();

#ifdef __cplusplus
}
#endif

#endif /*__MPP_BUFFER_H__*/
