#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int main1() {
    pid_t this;
    for (int i = 0; i < 5; i++) {
        if ((this = fork()) == 0)break;
    }

    if (this == 0) {
        printf("子进程，pid:%d，父进程ppid为:%d\n", getpid(), getppid());
        exit(0);
    } else if (this > 0) {
        printf("父进程，pid:%d", getpid());
    }
    sleep(1);

    return 0;
}
