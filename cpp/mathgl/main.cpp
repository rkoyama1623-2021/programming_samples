// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <iostream>
#include <mgl2/mgl.h>
int main()
{
  mglGraph gr;
  gr.FPlot("sin(pi*x)");
  gr.WriteFrame("test.png");
}
