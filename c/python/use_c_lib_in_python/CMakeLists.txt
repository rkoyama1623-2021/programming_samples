## declare the executable version of cmake.
cmake_minimum_required(VERSION 2.8)
find_package(PythonLibs 2.7 REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})

add_library(spam SHARED sample.c)
target_link_libraries(spam ${PYTHON_LIBRARIES})
set_target_properties(spam PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set_target_properties(spam PROPERTIES PREFIX "" SUFFIX ".so")