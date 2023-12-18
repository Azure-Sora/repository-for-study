#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define PTHREADS 100000

pthread_mutex_t countMutex;
pthread_mutex_t runningPthreadsMutex;
int runningPthreads;

void *incr(void *arg);

int main0() {
    pthread_mutex_init(&countMutex, NULL);
    pthread_mutex_init(&runningPthreadsMutex, NULL);
    pthread_t pthreads;
    int count = 0;
    for (int i = 0; i < PTHREADS; i++) {
        pthread_mutex_lock(&runningPthreadsMutex);
        runningPthreads++;
        pthread_mutex_unlock(&runningPthreadsMutex);
        pthread_create(&pthreads, NULL, incr, &count);
    }

    while (runningPthreads > 0) {
        sleep(1);
    }

    printf("count=%d", count);

    return 0;
}

void *incr(void *arg) {
    pthread_detach(pthread_self());
    int *num = (int *) arg;
    pthread_mutex_lock(&countMutex);
    (*num)++;
    pthread_mutex_unlock(&countMutex);
    pthread_mutex_lock(&runningPthreadsMutex);
    runningPthreads--;
    pthread_mutex_unlock(&runningPthreadsMutex);
    pthread_exit(NULL);

}