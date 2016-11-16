## declare the executable version of cmake.
cmake_minimum_required(VERSION 2.8)
find_package(PythonLibs 2.7 REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})

add_executable(main main.cpp)
target_link_libraries(main ${PYTHON_LIBRARIES})
