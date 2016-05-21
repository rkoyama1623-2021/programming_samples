if [ -e build ];then rm -rf build;fi
mkdir build;cd build;
cmake ..
make
if ! [ -e $? ];then export EXIT_STATUS=$?;fi
cd ..

./build/main
if ! [ -e $? ];then export EXIT_STATUS=$?;fi
gnuplot -p plot.plt
