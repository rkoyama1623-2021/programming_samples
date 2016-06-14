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
  ofstream outputfile("tracking2.csv");

  //make instance
  double m_dt=0.001;
  interpolator* i = new interpolator(1, m_dt,interpolator::HOFFARBIB,0.5);

  double start=0.0,goal=1.0,goalv=0;
  double test_time=10;
  double t=0;
  double x=0,v=0,a=0;
  double x_old=0,v_old=0,a_old=0;
  double rt;

  //i->load("data.csv");
  i->set(&start);

  for (int j=0;j<test_time/m_dt;j++){
    // set goal
    double target,c_target;
    double interpolation_time;
    double interpolation_gain=10;
    double Kp=0.01;
    target=target_pos(t);
    x_old=x;
    x=Kp*(target-x) +x;
    v_old=v;
    v=(x-x_old)/m_dt;
    a=(v-v_old)/m_dt;

    outputfile << t << " " << x << " " << v << " "<< a << " " << target <<std::endl;
    t+=i->deltaT();
  }
  outputfile.close();
  return 0;
};
