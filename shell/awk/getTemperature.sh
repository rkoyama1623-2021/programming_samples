#!/usr/bin/env bash
while :
do
    th=$(sensors|awk 'NR==3 && match($4, /[0-9][0-9].[0-9]/) { print substr($4, RSTART, RLENGTH) }')
    thFlag=$(awk "BEGIN{ if (${th}>90) { print 0 } else { print 1 }}")
    if $(exit ${thFlag}); then notify-send "CPU Temp=${th}"; fi
    sleep 1
done
