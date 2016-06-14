// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include "interpolator.h"
#include <iostream>
#include <iomanip>
#include<fstream>
#include<math.h>

double target_pos(double t){
  return sin(t);
  //return 1/(1+exp(-2*(t-4)));
  //return 1/(1+exp(-2*(t-4)))+0.01*sin(10*t);
}

int main () {
  // file to write
  ofstream outputfile("tracking.csv");

  //make instance
  double m_dt=0.001;
  interpolator* i = new interpolator(1, m_dt,interpolator::HOFFARBIB,0.5);

  double start=0.0,goal=1.0,goalv=0;
  double test_time=10;
  double t=0;
  double x=0,v=0,a=0;
  double rt;

  //i->load("data.csv");
  i->set(&start);

  for (int j=0;j<test_time/m_dt;j++){
    // set goal
    double target,c_target;
    double interpolation_time;
    double interpolation_gain=10;
    double Kp=0.1;
    target=target_pos(t);
    c_target=Kp*(target-x) +x;
    interpolation_time= 0.1;//interpolation_gain*fabs(x-target);
    //std::cout << fabs(x-target) << std::endl;
    // std::cout << interpolation_time << std::endl;

    i->setGoal(&c_target, interpolation_time, true);
    // get interpolation val
    if (i->isEmpty()) std::cout << "empty!" << std::endl;
    i->get(&x,&v,&a,true);
    outputfile << t << " " << x << " " << v << " "<< a << " " << target <<std::endl;
    t+=i->deltaT();
  }
  outputfile.close();
  return 0;
};
