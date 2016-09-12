#!/usr/bin/env bash

./build.sh; if ! $(exit $?);then EXIT_STATUS=1;fi
./build/main; if ! $(exit $?);then EXIT_STATUS=1;fi

exit $EXIT_STATUS
