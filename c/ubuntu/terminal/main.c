// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <stdio.h>
#include <unistd.h>

int main()
{
  char *message = "this is terminal";
  if( isatty(fileno(stdout)) ) {
    puts(message);
  }
  return 0;
}
