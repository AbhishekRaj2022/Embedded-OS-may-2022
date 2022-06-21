#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int count=0;
pthread_t r1,r2,w1;
pthread_rwlock_t count_rwlock;
void *Reader1(void *data)
{
    int z;
    printf("Reader1 : Entering Critical Section\n");
    pthread_rwlock_rdlock(&count_rwlock);
    printf("Reader1 :  inside Critical Section\n");
    z=count+10;
    printf("Reader1 : %d\n",count);
    pthread_rwlock_unlock(&count_rwlock);
    printf("Reader1 : Leaving Critical Section\n");


}


void *Reader2(void *data)
{
    int x;
    printf("Reader2 : Entering Critical Section\n");
    pthread_rwlock_rdlock(&count_rwlock);
    printf("Reader2 :  inside Critical Section\n");
    x=count+20;
    printf("Reader2 : %d\n",count);
    pthread_rwlock_unlock(&count_rwlock);
    printf("Reader2 : leaving Critical Section\n");

}


void *Writer1(void *data)
{
    printf("Writer1 : Entering Critical Section\n");
    pthread_rwlock_wrlock(&count_rwlock);
    printf("Writer1 :  inside Critical Section\n");
    count++;
    pthread_rwlock_unlock(&count_rwlock);
    printf("Writer1 : leaving Critical Section\n");


}


int main(int argc, char const *argv[])
{

    pthread_rwlock_init(&count_rwlock,NULL);
    pthread_create(&r1,NULL,Reader1,NULL);
    pthread_create(&r2,NULL,Reader2,NULL);
    pthread_create(&w1,NULL,Writer1,NULL);
    pthread_join(r1,NULL);
    pthread_join(r2,NULL);
    pthread_join(w1,NULL);


    return 0;
}

