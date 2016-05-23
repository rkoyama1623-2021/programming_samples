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

testList=(
    cpp/basic/.template/build.sh
    cpp/basic/inheritance/build.sh
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
exit ${EXIT_STATUS}
