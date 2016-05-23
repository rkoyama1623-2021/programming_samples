## declare the executable version of cmake.
cmake_minimum_required(VERSION 2.8)

set(LIBS glut GL GLU)

add_executable(cube cube.c)
target_link_libraries(cube ${LIBS})

add_executable(cube2 cube2.c)
target_link_libraries(cube2 ${LIBS})

add_executable(cube3 cube3.c)
target_link_libraries(cube3 ${LIBS})
