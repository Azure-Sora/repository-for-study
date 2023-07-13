#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *print(void *arg) {

    pthread_mutex_lock(&mutex);

    printf("hello");
    sleep(1);
    printf("world");
    sleep(1);

    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {

    pthread_t pthread;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&pthread, NULL, print, NULL);

    pthread_mutex_lock(&mutex);

    printf("hello");
    sleep(1);
    printf("world");
    sleep(1);

    pthread_mutex_unlock(&mutex);

    pthread_join(pthread, NULL);

    return 0;
}
