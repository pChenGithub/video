#include "sm4_core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG(format, ...)                                                     \
  printf("[%s]:%d: " format "\n", __func__, __LINE__, ##__VA_ARGS__)

static int aes_xts128_encrypt(void *ctx1, void *ctx2,
                              const unsigned char iv[16],
                              const unsigned char *inp, unsigned char *out,
                              unsigned long len, int enc) {
  const union {
    long one;
    char little;
  } is_endian = {1};
  union {
    u64 u[2];
    u32 d[4];
    u8 c[16];
  } tweak, scratch;
  unsigned int i;

  if (len < 16)
    return -1;

  memcpy(tweak.c, iv, 16);

  rk_sm4_crypt_ecb(ctx2, (const unsigned char *)tweak.c, tweak.c);

  if (!enc && (len % 16))
    len -= 16;

  while (len >= 16) {
    memcpy(scratch.c, inp, 16);
    scratch.u[0] ^= tweak.u[0];
    scratch.u[1] ^= tweak.u[1];

    if (enc)
      rk_sm4_crypt_ecb(ctx1, (const unsigned char *)scratch.c, scratch.c);
    else
      rk_sm4_crypt_ecb(ctx1, (const unsigned char *)scratch.c, scratch.c);

    scratch.u[0] ^= tweak.u[0];
    scratch.u[1] ^= tweak.u[1];
    memcpy(out, scratch.c, 16);

    inp += 16;
    out += 16;
    len -= 16;

    if (len == 0)
      return 0;

    if (is_endian.little) {
      unsigned int carry, res;

      res = 0x87 & (((int)tweak.d[3]) >> 31);
      carry = (unsigned int)(tweak.u[0] >> 63);
      tweak.u[0] = (tweak.u[0] << 1) ^ res;
      tweak.u[1] = (tweak.u[1] << 1) | carry;
    } else {
      size_t c;

      for (c = 0, i = 0; i < 16; ++i) {
        /*+ substitutes for |, because c is 1 bit */
        c += ((size_t)tweak.c[i]) << 1;
        tweak.c[i] = (u8)c;
        c = c >> 8;
      }
      tweak.c[0] ^= (u8)(0x87 & (0 - c));
    }
  }
  if (enc) {
    for (i = 0; i < len; ++i) {
      u8 c = inp[i];
      out[i] = scratch.c[i];
      scratch.c[i] = c;
    }
    scratch.u[0] ^= tweak.u[0];
    scratch.u[1] ^= tweak.u[1];
    rk_sm4_crypt_ecb(ctx1, (const unsigned char *)scratch.c, scratch.c);
    scratch.u[0] ^= tweak.u[0];
    scratch.u[1] ^= tweak.u[1];
    memcpy(out - 16, scratch.c, 16);
  } else {
    union {
      u64 u[2];
      u8 c[16];
    } tweak1;

    if (is_endian.little) {
      unsigned int carry, res;

      res = 0x87 & (((int)tweak.d[3]) >> 31);
      carry = (unsigned int)(tweak.u[0] >> 63);
      tweak1.u[0] = (tweak.u[0] << 1) ^ res;
      tweak1.u[1] = (tweak.u[1] << 1) | carry;
    } else {
      size_t c;

      for (c = 0, i = 0; i < 16; ++i) {
        /*+ substitutes for |, because c is 1 bit */
        c += ((size_t)tweak.c[i]) << 1;
        tweak1.c[i] = (u8)c;
        c = c >> 8;
      }
      tweak1.c[0] ^= (u8)(0x87 & (0 - c));
    }

    memcpy(scratch.c, inp, 16);
    scratch.u[0] ^= tweak1.u[0];
    scratch.u[1] ^= tweak1.u[1];

    rk_sm4_crypt_ecb(ctx1, (const unsigned char *)scratch.c, scratch.c);
    scratch.u[0] ^= tweak1.u[0];
    scratch.u[1] ^= tweak1.u[1];

    for (i = 0; i < len; ++i) {
      u8 c = inp[16 + i];
      out[16 + i] = scratch.c[i];
      scratch.c[i] = c;
    }

    scratch.u[0] ^= tweak.u[0];
    scratch.u[1] ^= tweak.u[1];
    rk_sm4_crypt_ecb(ctx1, (const unsigned char *)scratch.c, scratch.c);

    scratch.u[0] ^= tweak.u[0];
    scratch.u[1] ^= tweak.u[1];
    memcpy(out, scratch.c, 16);
  }

  return 0;
}

/* XTS makes use of two different keys, usually generated by splitting
 * the supplied block cipher's key in half.
 * Because of the splitting, users wanting AES 256 and AES 128 encryption
 * will need to choose key sizes of 512 bits and 256 bits respectively.
 */
int rk_sm4_xts_encrypt(const unsigned char *in, unsigned char *out,
                       unsigned int length, const unsigned char *key,
                       const int key_len, unsigned char *ivec, const int enc) {
  sm4_context ctx1, ctx2;

  if (key_len != 32)
    return -1;

  if (enc) {
    rk_sm4_setkey_enc(&ctx1, key);
  } else {
    rk_sm4_setkey_dec(&ctx1, key);
  }

  rk_sm4_setkey_enc(&ctx2, key + key_len / 2);

  return aes_xts128_encrypt(&ctx1, &ctx2, ivec, in, out, length, enc);
}
