## declare the executable version of cmake.
cmake_minimum_required(VERSION 2.8)

# find hrpsys cmake_modules
execute_process(
  COMMAND ${CMAKE_SOURCE_DIR}/find_hrpsys_source
  OUTPUT_VARIABLE HRPSYS_SOURCE
  RESULT_VARIABLE RESULT
  OUTPUT_STRIP_TRAILING_WHITESPACE)

set(CMAKE_MODULE_PATH ${HRPSYS_SOURCE}/cmake_modules)

set(HRPSYS_SEQ_DIR ${HRPSYS_SOURCE}/rtc/SequencePlayer)

# OpenRTM-aist(>= 1.0.0)
find_package(OpenRTM REQUIRED)
if(EXISTS "${OPENRTM_DIR}/include/openrtm-1.1/rtm/RTObjectStateMachine.h")
add_definitions(-DOPENRTM_VERSION_TRUNK)
endif()

# OpenHRP
find_package(OpenHRP REQUIRED)
include_directories(${OPENHRP_INCLUDE_DIRS})
link_directories(${OPENHRP_LIBRARY_DIRS})
if(UNIX)
    add_definitions(${OPENHRP_DEFINITIONS})
endif()

# set libs (for mainly mutex)
set(libs hrpModel-3.1 hrpCollision-3.1 hrpUtil-3.1 hrpsysBaseStub)

include_directories(${HRPSYS_SEQ_DIR})
add_executable(main main.cpp ${HRPSYS_SEQ_DIR}/interpolator.cpp)
target_link_libraries(main ${libs})

add_executable(main2 main2.cpp ${HRPSYS_SEQ_DIR}/interpolator.cpp)
target_link_libraries(main2 ${libs})


