cmake_minimum_required(VERSION 2.8)
# set(CMAKE_VERBOSE_MAKEFILE 1)

find_package(Boost COMPONENTS python REQUIRED) # for python
find_package(PythonLibs REQUIRED)
include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})

add_library(mymodule SHARED numpy.cpp)
target_link_libraries(mymodule ${Boost_LIBRARIES} ${PYTHON_LIBRARY} boost_numpy)
set_target_properties(mymodule PROPERTIES PREFIX "") # 接頭辞'lib'を省略するため