#include <omp.h>
#include <stdio.h>

int basic_for() {
#pragma omp parallel
  {
#pragma omp for // has implicit barrier
    for (int i = 0; i < 100; i++) {
      // some work
    }
    // all threads wait here
    printf("all threads reach this\n"); // executes after all loops done
  }
  // threads end here at end of parallel region

  // if we had nowait directive, it would not have an implicit barrier
#pragma omp parallel
  {
#pragma omp for nowait // no implicit barrier
    for (int i = 0; i < 100; i++) {
      // some work
    }
    // no waiting
    printf("all threads reach this\n"); // executes immediately
  }
  // threads end here at end of parallel region
  return 0;
}

int ordered_for() {
  int factor[4] = {5, 6, 7, 8};
  int arr[4] = {6, 1, 7, 0};

#pragma omp parallel for ordered shared(factor, arr)
  for (int i = 0; i < 4; i++) {
    printf("%d\n", i);
    arr[i] *= factor[i];

#pragma omp ordered
    {
      printf("ordered: %d\n", i);
    }
  }

  return 0;
}

int main() { ordered_for(); }
