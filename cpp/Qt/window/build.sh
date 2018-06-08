#!/usr/bin/env bash

if [ -e Makefile ];then rm -rf Makefile; fi
if [ -e window.pro ];then rm -rf window.pro; fi

qmake -project # make project
qmake # make makefile
make; if ! $(exit $?);then EXIT_STATUS=1;fi

# ./window; if ! $(exit $?);then EXIT_STATUS=1;fi

exit $EXIT_STATUS
