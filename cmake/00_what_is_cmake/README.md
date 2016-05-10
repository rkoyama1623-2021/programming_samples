# what is CMake?
This directory is a sample for cmake.
cmake is a tool to simplify your compiling.
you can compile main.cpp by the following command.
```
mkdir build
cd build;cmake ..# create makefile
make
```
Then you will find that executable file is in the build directory.
All settings for compile is in CMakeList.txt.

# display what is done
you can know the process executed by `make` command.
```
make VERBOSE=1
```
This is because the following line in `Makefile`
```
# Suppress display of executed commands.
$(VERBOSE).SILENT:
```
