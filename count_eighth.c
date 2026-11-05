#include <stdio.h>
#include <pthread.h>
#define NUM_LOOPS 600000000

long long sum = 0;



void* counting_up(void *arg){
        int offset = *(int*)arg;
        for (int i = 0; i < NUM_LOOPS; i++){
                sum += offset;
                }
        pthread_exit(NULL);
}

void* counting_down(void *arg){
        int offset = *(int*)arg;
        for (int i = 0; i < NUM_LOOPS; i++){
                sum -= offset;
        }
        pthread_exit(NULL);
}

int main(void){
        int offset = 1;
        pthread_t id1;
        pthread_t id2;
        pthread_create(&id1, NULL, counting_up, &offset);
        pthread_create(&id2, NULL, counting_down, &offset);
        pthread_join(id1, NULL);
        pthread_join(id2, NULL);
        printf("Sum = %lld\n", sum);
}

