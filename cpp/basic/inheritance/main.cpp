// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <iostream>

struct parent{
  int a,b;
public:
  parent():a(1), b(2) {//use initialization list
    std::cout << "generate parent" << std::endl;
  };
};

struct child : parent {
  int c;
public:
  child():parent(){
    a=3;
    std::cout << "generate child" << std::endl;
  };
};

int main () {
  parent p;
  child c;
  std::cout << "p.a=" << p.a << std::endl;
  std::cout << "c.a=" << c.a << std::endl;
  return 0;
};
