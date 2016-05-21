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

testList=(cpp/basic/.template/build.sh cpp/basic/inheritance/build.sh cpp/hrpsys/sequence_player/build.sh)
topDir=$(pwd)

echo "echo = $ECHO"

for test in ${testList[@]}; do
    execute cd ${topDir}
    execute cd $(dirname ${test})
    execute ./$(basename ${test})
    if ! test ${?} -eq 0;then 
        echo "test fail.";
    else
        echo "test pass!"
    fi
    if [ -e build ];then execute rm -rf build; fi;
done
execute cd ${topDir}

