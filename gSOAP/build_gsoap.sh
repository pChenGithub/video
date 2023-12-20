#! /bin/sh

# 指定源码目录(解压源码)
GSOAP_SRC=gsoap-2.8
PWD=`pwd`

echo "build gsoap..."

cd $GSOAP_SRC

# 配置,指定安装目录
./configure --prefix=${PWD}/gsoap_x86
make -j8 && make install

cd -

