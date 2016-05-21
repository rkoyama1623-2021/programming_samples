// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include "interpolator.h"
#include <iostream>
#include <iomanip>
#include<fstream>

int main () {

// file to write
  ofstream outputfile("sample.csv");

  //make instance
  double m_dt=0.001;
  interpolator* i = new interpolator(1, m_dt,interpolator::HOFFARBIB,0.5);
  if (i->isEmpty()) {
    std::cout<< "#empty!" << std::endl;
  };

  double start=0.0,goal=1.0,goalv=0;
  double t=0;
  double x,v,a;
  double rt;

  //i->load("data.csv");
  std::cout << "loaded. empty?:" << i->isEmpty() << std::endl;
  i->set(&start);
  i->setGoal(&goal,&goalv, 1.0, true);

  while (! i->isEmpty()) {
  //for (int j=0;j<10;j++){
    i->get(&x,&v,&a,true);
    // if (j==5) {
    //   std::cout<< "j=5" << std::endl;
    //   i->clear();
    //   start=2.0;
    //   goal=0;
    //   i->set(&start);
    //   i->setGoal(&goal, 0.5, true);
    // };
    outputfile << t << " " << x << " " << v << " "<< a << "" <<std::endl;
    t+=i->deltaT();
  }
  outputfile.close();
  return 0;
};
