## declare the executable version of cmake.
cmake_minimum_required(VERSION 2.8)
# generage files necesarry to compile.

add_executable(myapp main.cpp)

message("CMAKE_SOURCE_DIR" ${CMAKE_SOURCE_DIR})
message("CMAKE_BINARY_DIR" ${CMAKE_BINARY_DIR})
message("CMAKE_CURRENT_SOURCE_DIR" ${CMAKE_CURRENT_SOURCE_DIR})
message("CMAKE_CURRENT_BINARY_DIR" ${CMAKE_CURRENT_BINARY_DIR})


set(build_dir ${CMAKE_CURRENT_LIST_DIR}/build)
execute_process(
  COMMAND message("CMAKE_CURRENT_SOURCE_DIR" ${CMAKE_CURRENT_SOURCE_DIR})
  # COMMAND message("CMAKE_CURRENT_BINARY_DIR" ${CMAKE_CURRENT_BINARY_DIR})
  WORKING_DIRECTORY ${build_dir}
)