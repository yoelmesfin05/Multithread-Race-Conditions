#include <stdio.h>
#include <pthread.h>
#define NUM_LOOPS 600000000

long long sum = 0;

void* counting_thread(void *arg){

        for (int i = 0; i < NUM_LOOPS; i++){
                sum++;
                }
        pthread_exit(NULL);
}

int main(void){

        pthread_t id1;
        pthread_create(&id1, NULL, counting_thread, NULL);
        pthread_join(id1, NULL);
        printf("Sum = %lld\n", sum);
}

