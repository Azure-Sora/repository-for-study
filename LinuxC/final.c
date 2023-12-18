#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t buf1_empty;
sem_t buf2_empty;
sem_t buf1_full;
sem_t buf2_full;

int buf1;
int buf2;

int file1_end = 0;
int file2_end = 0;

void* reader(void* buf_num)
{
    int bf_num = *((int*)buf_num);
    if(bf_num == 1)
    {
        printf("rd1");
        FILE* file = fopen("1.dat","r");
        while(!feof(file))
        {
            sem_wait(&buf1_empty);
            fscanf(file,"%d",&buf1);
            sem_post(&buf1_full);
        }
        file1_end = 1;
        fclose(file);

    }
    else
    {
        printf("rd2");
        FILE* file = fopen("2.dat","r");
        while(!feof(file))
        {
            sem_wait(&buf2_empty);
            fscanf(file,"%d",&buf2);
            sem_post(&buf2_full);
        }
        file2_end = 1;
        fclose(file);

    }
}

void* calculator()
{
    while(1)
    {
        sem_wait(&buf1_full);
        sem_wait(&buf2_full);
        printf("%d + %d = %d , %d * %d = %d \n",buf1,buf2,buf1+buf2,buf1,buf2,buf1*buf2);
        sem_post(&buf1_empty);
        sem_post(&buf2_empty);
        if(file1_end == 1 && file2_end == 1) break;
    }
}


int main()
{
    int one = 1;
    int two = 2;
    printf("111");
    sem_init(&buf1_empty,1,1);
    sem_init(&buf2_empty,1,1);
    sem_init(&buf1_full,1,0);
    sem_init(&buf2_full,1,0);
    pthread_t rd1;
    pthread_t rd2;
    pthread_t cal;
    pthread_create(&rd1,NULL,reader,&one);
    pthread_create(&rd2,NULL,reader,&two);
    pthread_create(&cal,NULL,calculator,NULL);
    pthread_join(rd1,NULL);
    pthread_join(rd2,NULL);
    pthread_join(cal,NULL);
}