// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <stdio.h>
#include <stdlib.h>

#define N 10

int main (int argc, char *argv[]) 
{

#ifdef _OPENMP
#pragma omp parallel for
#endif
  for(int i=0;i<N;i++)
    {
      printf("Hello World from thread = %d\n", i);
    }

  printf("=====================\n");

  for(int i=0;i<N;i++)
    {
      printf("Hello World from thread = %d\n", i);
    }

}

