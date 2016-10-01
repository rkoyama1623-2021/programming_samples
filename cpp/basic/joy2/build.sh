#!/usr/bin/env bash

if [ -e build ];then rm -rf build;fi
mkdir build;cd build;
cmake -DCMAKE_BUILD_TYPE=Debug ..
make; if ! $(exit $?);then EXIT_STATUS=1;fi
cd ..

./build/keyboard_joy; if ! $(exit $?);then EXIT_STATUS=1;fi

exit $EXIT_STATUS
