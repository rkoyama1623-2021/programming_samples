// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <boost/timer/timer.hpp>

int main()
{

boost::timer::auto_cpu_timer t;

for (int i=0; i< 10000; i++)
  1+1;
}
