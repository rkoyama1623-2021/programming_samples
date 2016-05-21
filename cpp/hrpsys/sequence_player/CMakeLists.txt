## declare the executable version of cmake.
cmake_minimum_required(VERSION 2.8)

# find hrpsys cmake_modules
execute_process(
  COMMAND ${CMAKE_SOURCE_DIR}/find_hrpsys_cmake_modules
  OUTPUT_VARIABLE HRPSYS_SOURCE_CMAKE_MODULES
  RESULT_VARIABLE RESULT
  OUTPUT_STRIP_TRAILING_WHITESPACE)
message(RESULT: ${RESULT})
message(HRPSYS_SOURCE_CMAKE_MODULES: ${HRPSYS_SOURCE_CMAKE_MODULES})

set(CMAKE_MODULE_PATH ${HRPSYS_SOURCE_CMAKE_MODULES})

# find seq dir in hrpsys
execute_process(
  COMMAND rospack find hrpsys
  OUTPUT_VARIABLE HRPSYS_DEVEL_TOP_PATH
  RESULT_VARIABLE RESULT
  OUTPUT_STRIP_TRAILING_WHITESPACE)
set(HRPSYS_SEQ_DIR ${HRPSYS_DEVEL_TOP_PATH}/src/rtc/SequencePlayer)

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


