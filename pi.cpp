/*
This program will numerically compute the integral of

                  4/(1+x*x) 
          
from 0 to 1.  The value of this integral is pi -- which 
is great since it gives us an easy way to check the answer.

The is the original sequential program.  It uses the timer
from the OpenMP runtime library

History: Written by Tim Mattson, 11/99.

*/

// to compile and run the program type: g++ pi.cpp -O3 -fopenmp -o pi.out; ./pi.out

// TODO: 1. parallelize with OpenMP using only #pragma omp parallel
//       2. parallelize with OpenMP making as small changes in the program as possible

#include <stdio.h>
#include <omp.h>

static long num_steps = 100000000;
double step;
int main ()
{
    int i, id, istart, iend, Nthrds = 10;
    double x, pi, sum = 0.0;
    double start_time, run_time;
    double sumThreads[Nthrds];
    omp_set_num_threads(Nthrds);
    step = 1.0/(double) num_steps;
    start_time = omp_get_wtime();
  #pragma omp parallel
  {
    id = omp_get_thread_num();
    istart = (id * num_steps)/ Nthrds;
    iend = istart+(num_steps/Nthrds);
           
    for (i=istart ;i<= iend; i++){
      x = (i-0.5)*step;
      sumThreads[id] = sumThreads[id] + 4.0/(1.0+x*x);
    }
  }

  for(int ii = 0; ii < Nthrds; ii++){
    sum += sumThreads[ii];
  }

    pi = step * sum;
    run_time = omp_get_wtime() - start_time;
    printf("\n pi with %d steps is %f in %f seconds \n",num_steps,pi,run_time);
}
