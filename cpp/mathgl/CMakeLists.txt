## declare the executable version of cmake.
cmake_minimum_required(VERSION 2.8)

# set(LIBS libmgl-qt.a libmgl.a libmgl-glut.a libmgl-wnd.a libmgl-wx.a libmgl-mpi.a libmgl-fltk.a)
# set(LIBS mgl mgl-qt mgl mgl-glut mgl-wnd mgl-wx mgl-mpi mgl-fltk)
set(LIBS mgl)

link_directories(/usr/lib)


add_executable(main main.cpp)
target_link_libraries(main ${LIBS})
