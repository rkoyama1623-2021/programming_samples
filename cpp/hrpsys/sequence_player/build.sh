echo "check dependant packages"
echo "hrpsys"
echo "----->" locate -r 'hrpsys/cmake_modules$'
echo $(locate -r 'hrpsys/cmake_modules$')
echo "----->" rospack find openrtm_aist
echo $(rospack find openrtm_aist)
echo "----->" rospack find openhrp3
echo $(rospack find openhrp3)

if [ -e build ];then rm -rf build;fi
mkdir build;cd build;
cmake ..
make
if ! [ -e $? ];then export EXIT_STATUS=$?;fi
cd ..

./build/main
./build/main2
if ! [ -e $? ];then export EXIT_STATUS=$?;fi
gnuplot -p plot.plt
gnuplot -p plot2.plt
