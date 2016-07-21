// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <iostream>
#include <boost/bind.hpp>
#include <boost/function.hpp>

typedef boost::function<int()> TestFunction;

class Sample
{
public:
  Sample()
  {
    Val = 5;
  }
  int GetVal()
  {
    return Val;
  }
  int Val;
};

int main()
{
  TestFunction Tf;
  Sample Smp;
  int Result = 0;

  // generate a kind of function pointer(Tf), which looks like pointer to Sample::GetVal.
  Tf = boost::bind(&Sample::GetVal, Smp); // first arg is function, second arg is instance which have function
  Result = Tf();
  std::cout << "Result=" << Result  << std::endl;
  return 0;
}
