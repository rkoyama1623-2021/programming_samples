// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <iostream>
#include <map>
#include <iterator>

int main () {
  std::map<std::string, int> mp;
  mp["a"] = 1;
  mp["b"] = 2;
  mp["c"] = 3;

  for ( std::map<std::string, int>::iterator itr = mp.begin(); itr != mp.end(); itr++ ) {
    std::cout << itr->first << "=" << itr->second << std::endl;
  };


  return 0;
};
