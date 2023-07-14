#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void cp(const char *src, const char *dest);

void fragmentCp(const char *src, const char *dest);

void pthreadCp(const char *src, const char *dest);

void *copyThisFragment(void *arg);

typedef struct {
    const char *src;
    const char *dest;
    int myPosition;
    int isLast;
} AFragment;

int main2() {
//    cp("a.txt", "b.txt");
//    fragmentCp("aa.txt", "bb.txt");
    pthreadCp("aa.txt", "bb.txt");

    return 0;
}

void cp(const char *src, const char *dest) {
    int srcFile = open(src, O_RDONLY);
    if (srcFile == -1) {
        fprintf(stdout, "File not exist!");
        return;
    }
    int destFile = open(dest, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (destFile == -1) {
        fprintf(stdout, "Fail to copy!");
        return;
    }
    off_t fileSize = lseek(srcFile, 0, SEEK_END);
    char *buf = malloc(fileSize);
    lseek(srcFile, 0, SEEK_SET);
    read(srcFile, buf, fileSize * sizeof(char));
    write(destFile, buf, fileSize);
    free(buf);
    close(srcFile);
    close(destFile);
}

void fragmentCp(const char *src, const char *dest) {
    int srcFile = open(src, O_RDONLY);
    if (srcFile == -1) {
        fprintf(stdout, "File not exist!");
        return;
    }
    int destFile = open(dest, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (destFile == -1) {
        fprintf(stdout, "Fail to copy!");
        return;
    }
    char *buf = malloc(1024);
    off_t size = lseek(srcFile, 0, SEEK_END);
    lseek(destFile, size, SEEK_SET);
    write(destFile, "", 1);
    lseek(srcFile, 0, SEEK_SET);
    lseek(destFile, 0, SEEK_SET);
    for (;;) {
        char a[1];
        if (read(srcFile, a, 1) <= 0) {
            break;
        }
        lseek(srcFile, -1, SEEK_CUR);
        read(srcFile, buf, 1024);
        write(destFile, buf, 1024);
    }
}

void pthreadCp(const char *src, const char *dest) {
    int srcFile = open(src, O_RDONLY);
    if (srcFile == -1) {
        fprintf(stdout, "File not exist!");
        return;
    }
    int destFile = open(dest, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (destFile == -1) {
        fprintf(stdout, "Fail to copy!");
        return;
    }
    off_t size = lseek(srcFile, 0, SEEK_END);
    lseek(destFile, size, SEEK_SET);
    write(destFile, "", 1);
    lseek(srcFile, 0, SEEK_SET);
    lseek(destFile, 0, SEEK_SET);
    int pthreadCount = size / 1024 + 1;
    pthread_t *pthreads = malloc(pthreadCount * sizeof(pthread_t));
    int nowAtFragment = 0;
    while (nowAtFragment < pthreadCount) {
        AFragment *this = malloc(sizeof(AFragment));
        this->src = src;
        this->dest = dest;
        this->myPosition = nowAtFragment;
        this->isLast = (nowAtFragment == (pthreadCount - 1) ? 1 : 0);
        pthread_create(&(pthreads[nowAtFragment]), NULL, copyThisFragment, this);
        nowAtFragment++;
    }
    pthread_join(pthreads[pthreadCount - 1], NULL);
}

void *copyThisFragment(void *arg) {
    char buf[1024];
    AFragment *this = (AFragment *) arg;
    int srcFile = open(this->src, O_RDONLY);
    int destFile = open(this->dest, O_RDWR);
    int size = 1024;
    if (this->isLast == 1) {
        size = lseek(srcFile, 0, SEEK_END) - this->myPosition * 1024;
    }
    lseek(srcFile, this->myPosition * 1024, SEEK_SET);
    lseek(destFile, this->myPosition * 1024, SEEK_SET);
    read(srcFile, buf, size);
    write(destFile, buf, size);
    close(srcFile);
    close(destFile);
    pthread_exit(NULL);
}