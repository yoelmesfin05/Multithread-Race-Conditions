#include <stdio.h>
#include <pthread.h>
#define NUM_LOOPS 20000000

long long sum = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* counting_up(void *arg){

        for (int i = 0; i < NUM_LOOPS; i++){
                pthread_mutex_lock(&mutex);
                sum++;
                pthread_mutex_unlock(&mutex);
                }
        pthread_exit(NULL);
}

void* counting_down(void *arg){

        for (int i = 0; i < NUM_LOOPS; i++){
                pthread_mutex_lock(&mutex);
                sum--;
                pthread_mutex_unlock(&mutex);
                }
        pthread_exit(NULL);
}

int main(void){

        pthread_t id1;
        pthread_t id2;
        pthread_create(&id1, NULL, counting_up, NULL);
        pthread_create(&id2, NULL, counting_down, NULL);
        pthread_join(id1, NULL);
        pthread_join(id2, NULL);
        printf("Sum = %lld\n", sum);
}