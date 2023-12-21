#! /bin/sh

OUT_DIR=out_x86
SRC_DIR=v4l2rtspserver

echo "build v4l2rtspserver"

if [ ! -d $OUT_DIR ];then
    mkdir $OUT_DIR
fi

cd $OUT_DIR
cmake ../${SRC_DIR}
make -j4

cd -