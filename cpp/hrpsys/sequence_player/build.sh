if [ -e build ];then rm -rf build;fi
mkdir build;cd build;
cmake ..
make
cd ..

./build/main
gnuplot -p plot.plt

