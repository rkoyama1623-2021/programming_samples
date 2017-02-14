#!/usr/bin/env bash

# ------------------
# for display results
# ------------------
function usage (){
    echo "this is command for test"
}
function execute (){
    echo "--->" $@
    if ! ${ECHO}; then ${ECHO} $@; else ${@}; fi;
}
OPT=`getopt -o hipeynsr: -l help, -- $*`
eval set -- $OPT
while [ -n "$1" ] ; do
    case $1 in
	-h|--help) usage;shift ;;
        -n) shift;ECHO="echo";;
	--) shift; break;;
	*) echo "Unknown option($1)"; usage;shift;;
    esac
done


# ------------------
# install dependances
# ------------------
echo "install dependances ------------!"
sudo apt-get update
files=($(find . -name ".dependencies"))
for f in ${files[@]};do
    source ${f}
done


# ------------------
# test each program
# ------------------
echo "test start ---------------------! "
testList=(
    c/ubuntu/terminal/build.sh
    c/ubuntu/pty_sample/build.sh
    cpp/basic/.template/build.sh
    cpp/basic/inheritance/build.sh
    cpp/basic/string/build.sh
    cpp/basic/bit/build.sh
    cpp/boost/binding/build.sh
    cpp/openGL/2d/build.sh
    cpp/openGL/showCube/build.sh
    cpp/Qt/window/build.sh
    cpp/OpenMP/build.sh
    cpp/pybind11/python_sample/build.sh
    cpp/pybind11/numpy_sample/build.sh
    python/03_convert_data_type/build.sh
    cmake/03_find_package/build.sh
)
topDir=$(pwd)

export EXIT_STATUS=0;
for test in ${testList[@]}; do
    execute cd ${topDir}
    execute cd $(dirname ${test})
    execute ./$(basename ${test})
    if ! test ${?} -eq 0;then 
        echo "test fail.";
        export EXIT_STATUS=1;
    else
        echo "test pass!"
    fi
    if [ -e build ];then execute rm -rf build; fi;
done
execute cd ${topDir}
if $(exit ${EXIT_STATUS});then echo "test pass!!!";else echo "test fail...";fi
exit ${EXIT_STATUS}
