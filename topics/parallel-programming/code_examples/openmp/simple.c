#include <omp.h>
#include <stdio.h>

int main() {
  printf("Starting a parallel region, spawning threads\n");

#pragma omp parallel
  {
    printf("Hello world, I am thread %d out of %d running threads!\n",
           omp_get_thread_num(), omp_get_num_threads());
  }

  printf("There are %d threads running!\n", omp_get_num_threads());
  return 0;
}
