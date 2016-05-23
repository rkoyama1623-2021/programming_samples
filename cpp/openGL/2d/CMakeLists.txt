## declare the executable version of cmake.
cmake_minimum_required(VERSION 2.8)

# # load the module to use pkg-config
# find_package(PkgConfig)

# # search library with pkg-config and name its results "LIBSAMPLE"
# pkg_check_modules(LIBOPENGL REQUIRED gl)

# message(LIBOPENGL: ${LIBOPENGL})
# message(LIBOPENGL_INCLUDE_DIRS: ${LIBOPENGL_INCLUDE_DIRS})
# message(LIBOPENGL_LIBRARIES: ${LIBOPENGL_LIBRARIES})

# # use the variable <RESULTNAME>_INCLUDE_DIRS to get include paths
# include_directories(${LIBOPENGL_INCLUDE_DIRS})
set(LIBS glut GL GLU)

add_executable(main main.c)
target_link_libraries(main ${LIBS})

add_executable(main2 main2.c)
target_link_libraries(main2 ${LIBS})

add_executable(main3 main3.c)
target_link_libraries(main3 ${LIBS})
