#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;

typedef struct {
    int a;
    const char *b;
} id;

void *print(void *arg) {

    id *this = (id *) arg;
    pthread_mutex_lock(&mutex);

    printf("hello");
    sleep(1);
    printf("world");
    sleep(1);

    printf("a=%d , b=%s", this->a, this->b);

    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main0() {

    pthread_t pthread;
    pthread_mutex_init(&mutex, NULL);

    id *myid = malloc(sizeof(id));
    myid->a = 5;
    myid->b = "abc";

    pthread_create(&pthread, NULL, print, myid);

    pthread_mutex_lock(&mutex);

    printf("hello");
    sleep(1);
    printf("world");
    sleep(1);

    pthread_mutex_unlock(&mutex);

    pthread_join(pthread, NULL);

    return 0;
}
