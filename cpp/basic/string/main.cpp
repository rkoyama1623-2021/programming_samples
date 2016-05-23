// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <iostream>
#include <stdio.h>

int main () {
  std::string a("foo");
  std::string b("bar");
  if (a==b)  std::cout << "a=b" << std::endl;//std::string can compare by "="
  printf("%s\n" ,a.c_str());//std::string can be used as c format
  return 0;
};
