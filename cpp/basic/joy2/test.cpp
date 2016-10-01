// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-

#include <stdio.h>
#include <memory>
#include "getch.h"

namespace std {
using namespace tr1; // std::tr1:: => std::
}

int main(void)
{
  char *c=NULL;
  std::shared_ptr<GetCharacter> ptr(new GetCharacter(3,0));
  // ptr -> initTermios(0);
  ptr -> read (&c, 3);
  printf("%d/%d/%d\n", c[0], c[1], c[2]);
  ptr -> resetTermios();

}
