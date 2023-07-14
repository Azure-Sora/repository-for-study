#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

#define NUMBER_COUNT 50000000
#define THREADS_COUNT 5

void *sort(int *nums);

void *threadsProcess(void *arg);

void merge(int arr[], int L, int M, int R);

pthread_mutex_t runningMutex;
int runningThreads;
int nums[NUMBER_COUNT];

typedef struct {
    int id;
    int *target;
} info;

int main6() {

    srand((int) time(NULL));
    for (int i = 0; i < NUMBER_COUNT; i++) {
        nums[i] = rand();
    }
    /*for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i) {
        printf(" %d ", nums[i]);
    }
    printf("\n");*/
    sort(nums);
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i) {
        printf(" %d ", nums[i]);
    }

}

void *sort(int *nums) {

    pthread_t pth;
    for (int i = 0; i < THREADS_COUNT; i++) {
        info *this = malloc(sizeof(info));
        this->id = i;
        this->target = nums;
        pthread_create(&pth, NULL, threadsProcess, this);
        pthread_mutex_lock(&runningMutex);
        runningThreads++;
        pthread_mutex_unlock(&runningMutex);
    }
    while (runningThreads > 0) {
        sleep(1);
    }

    for (int i = 0; i < THREADS_COUNT; i++) {
        int fragmentSize = NUMBER_COUNT / THREADS_COUNT;
        merge(nums, 0, fragmentSize * i - 1, fragmentSize * (i + 1) - 1);
    }

}

int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

void *threadsProcess(void *arg) {
    pthread_detach(pthread_self());

    info this = *((info *) arg);

    int fragmentSize = NUMBER_COUNT / THREADS_COUNT;

    qsort(this.target + fragmentSize * this.id, fragmentSize, sizeof(int), compare);

    pthread_mutex_lock(&runningMutex);
    runningThreads--;
    pthread_mutex_unlock(&runningMutex);

    pthread_exit(NULL);
}

void merge(int arr[], int L, int M, int R) {
    int *help = malloc((R - L + 1) * sizeof(int));
    int i = 0;
    int p1 = L;
    int p2 = M + 1;
    while (p1 <= M && p2 <= R) {
        help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= M) {
        help[i++] = arr[p1++];
    }
    while (p2 <= R) {
        help[i++] = arr[p2++];
    }
    for (i = 0; i < (R - L + 1); i++) {
        arr[L + i] = help[i];
    }
}
