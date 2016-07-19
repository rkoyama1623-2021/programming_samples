// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-

#include <iostream>
#include <boost/function.hpp>

typedef boost::function<int(int, int)> TestFunction;

int sum(int a, int b)
{
  return a + b;
}

int main()
{
  // pointer 
  TestFunction Tf;
  int (*pFunc)(int,int);
  // results
  int Result = 0;
  int Result2 = 0;
  //point function
  Tf = &sum;
  pFunc= &sum;
  //get results
  Result = Tf(2, 5);
  Result2 =pFunc(2,5);
  //print results
  std::cout << "result (using boost::function)=" << Result << std::endl;
  std::cout << "result (using function pointer)=" << Result2 << std::endl;

  return 0;
}
