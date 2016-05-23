#!/usr/bin/env bash

if [ -e build ];then rm -rf build;fi
mkdir build;cd build;
cmake ..
make
if ! $(exit $?);then EXIT_STATUS=1;fi
cd ..

./build/main in.png out.png
if ! $(exit $?);then EXIT_STATUS=1;fi

exit $EXIT_STATUS

