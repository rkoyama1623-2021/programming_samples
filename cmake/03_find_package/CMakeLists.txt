## declare the executable version of cmake.
cmake_minimum_required(VERSION 2.8)

# load the module to use pkg-config
find_package(PkgConfig)

# search library with pkg-config and name its results "LIBPNG"
pkg_check_modules(LIBPNG REQUIRED libpng)

message(LIBPNG: ${LIBPNG})
message(LIBPNG_INCLUDE_DIRS: ${LIBPNG_INCLUDE_DIRS})
message(LIBPNG_LIBRARIES: ${LIBPNG_LIBRARIES})

# use the variable <RESULTNAME>_INCLUDE_DIRS to get include paths
include_directories(${LIBPNG_INCLUDE_DIRS})

# support "for (int i=0;i<10,i++) ..." instead of "int i; for (i=0;i<10,i++) ..."
#set_property(TARGET main PROPERTY C_STANDARD 99) # CMake 3.1~
set(CMAKE_C_FLAGS "-std=c99")

add_executable(main main.c)
target_link_libraries(main ${LIBPNG_LIBRARIES})

