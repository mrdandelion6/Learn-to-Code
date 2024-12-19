#include <pthread.h>
#include <stdio.h>

#define N_THREADS 8
pthread_t threads[N_THREADS];

void* thread_routine(void* arg) {
    int x = (int)arg;
    return x;
}

int main() {
    for (int i = 0; i < N_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_routine, (void*)i);
    }
    for (int i = 0; i < N_THREADS; i++) {
        int ret;
        pthread_join(threads[i], (void*)ret);
        printf("ret val is: %d\n", ret);
    }
    
    return 0;
}