#!/usr/bin/env bash

if [ -e build ];then rm -rf build;fi
python setup.py build; if ! $(exit $?);then EXIT_STATUS=1;fi

exit $EXIT_STATUS
