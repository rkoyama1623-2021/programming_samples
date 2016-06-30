// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <iostream>
int main () {
  int a,b=0;
  //a|=b <<1 <=> shift b 1 , bitor a b
  b=1; a|=b<<0;
  b=0; a|=b<<1;
  b=1; a|=b<<2;
  b=1; a|=b<<3;

  //a=0x1101 i.e. a=13
  std::cout << a << std::endl;

  return 0;
};
