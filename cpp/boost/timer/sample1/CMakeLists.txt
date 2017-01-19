## declare the executable version of cmake.
cmake_minimum_required(VERSION 2.8)
find_package(Boost)
message(Boost_FOUND= ${Boost_FOUND})
message(Boost_LIBRARIES= ${Boost_LIBRARIES})
message(Boost_LIBRARY_DIRS= ${Boost_LIBRARY_DIRS})
message(Boost_THREAD_LIBRARY= ${Boost_THREAD_LIBRARY})
include_directories(${Boost_INCLUDE_DIRS})
add_executable(main main.cpp)
target_link_libraries(main boost_timer boost_system)

