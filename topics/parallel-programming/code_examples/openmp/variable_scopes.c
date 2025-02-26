#include <omp.h>
#include <stdio.h>

int main() {
  int shared_var = 42;

#pragma omp parallel shared(shared_var)
  {
    // all threads see and modify the same shared_var
    if (omp_get_thread_num() == 0) {
      shared_var = 100; // One thread changes it
    }

#pragma omp barrier // wait for all threads
    printf("Thread %d sees shared_var as %d\n", omp_get_thread_num(),
           shared_var); // all will print 100
  }
}
