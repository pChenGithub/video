#! /bin/sh

BIN_DIR=gsoap_x86/bin
PWD=`pwd`
OUT_DIR=MobileCode

echo "auto code create"

echo ${PWD}
cd ${OUT_DIR}

${PWD}/../${BIN_DIR}/wsdl2h -o $1 -c -s -t typemap.dat $2
${PWD}/../${BIN_DIR}/soapcpp2 -2 -C -c -x -Iimport -Icustom $1

cd -

echo "OK"


