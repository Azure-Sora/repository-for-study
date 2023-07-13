#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void cp(const char *src, const char *dest);

void fragmentCp(const char *src, const char *dest);

int main1() {
    cp("a.txt", "b.txt");
    fragmentCp("aa.txt", "bb.txt");


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