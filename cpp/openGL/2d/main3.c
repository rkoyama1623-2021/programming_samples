// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-

/* openGL test */

#include <GL/glut.h>

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glRotated(25.0, 1.0, 1.0, 0.0);
  glBegin(GL_POLYGON);
  glColor3d(1.0, 0.0, 0.0); /* 赤 */
  glVertex2d(-0.9, -0.9);
  glColor3d(0.0, 1.0, 0.0); /* 緑 */
  glVertex2d(0.9, -0.9);
  glColor3d(0.0, 0.0, 1.0); /* 青 */
  glVertex2d(0.9, 0.9);
  glColor3d(1.0, 1.0, 0.0); /* 黄 */
  glVertex2d(-0.9, 0.9);
  glEnd();
  glFlush();
}

void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 1.0);//set blue
}

int main(int argc, char *argv[])
{
  /*initialize window*/
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);//set color mode
  glutCreateWindow(argv[0]);
  /*register function to draw*/
  glutDisplayFunc(display); //callback function
  /*first process*/
  init();//process to set color
  /*execute loop using calback function*/
  glutMainLoop();
  return 0;
}
