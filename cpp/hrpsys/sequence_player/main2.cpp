// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include "interpolator.h"
#include <iostream>
#include <iomanip>
#include<fstream>

int main () {

// file to write
  ofstream outputfile("sample2.csv");

  //make instance
  double m_dt=0.001;
  interpolator* i = new interpolator(1, m_dt,interpolator::HOFFARBIB,0.5);
  if (i->isEmpty()) {
    std::cout<< "interpolater is  empty!" << std::endl;
  };

  double start=0.0,goal=1.0,goalv=0;
  double t=0;
  double x,v,a;
  double remain_t;

  i->set(&start);
  i->go(&goal,&goalv, 1.0, true);

  while (! i->isEmpty()) {
    i->get(&x,&v,&a,true);
    remain_t=i->remain_time();
    outputfile << t << " " << x << " " << v << " "<< a << " " << remain_t <<std::endl;
    t+=i->deltaT();
  }
  outputfile.close();
  return 0;
};
