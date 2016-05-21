cmake_minimum_required(VERSION 2.8)

set(build_dir ${CMAKE_CURRENT_LIST_DIR}/build)

if(NOT EXISTS ${build_dir})
  file(MAKE_DIRECTORY ${build_dir})
  execute_process(
    COMMAND ${CMAKE_COMMAND} ..
    WORKING_DIRECTORY ${build_dir}
  )
endif()

execute_process(
  COMMAND make all "ARGS='${CMAKE_ARGV3}'"
  WORKING_DIRECTORY ${build_dir}
)