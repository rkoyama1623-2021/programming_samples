## declare the executable version of cmake.
cmake_minimum_required(VERSION 2.8)
project(keyboard_joy)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES beginner_tutorials
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS}/boost/tr1/tr1)
link_directories(${PROJECT_SOURCE_DIR}/lib)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

IF(CMAKE_BUILD_TYPE MATCHES Debug)
  message("Debug build.")
ELSEIF(CMAKE_BUILD_TYPE MATCHES Release)
  message("Release build.")
ELSE()
  message("Some other build type.")
ENDIF()

add_library(getch SHARED getch.cpp)
set_target_properties(getch PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_executable(test test.cpp)
target_link_libraries(test getch)
# set_target_properties(main PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(keyboard_joy keyboard_joy.cpp)
target_link_libraries(keyboard_joy getch ${catkin_LIBRARIES})
