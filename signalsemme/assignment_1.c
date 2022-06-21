// Synchronization using signaling

#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

int a,b;
pthread_t input,process;
sem_t sem_i2p, sem_p2i;

void *Inputthread(void *data)
{
    while(1)
    {
        sem_wait(&sem_p2i);
        scanf("%d",&a);
        scanf("%d1",&b);
        sem_post(&sem_i2p);
        sem_post(&sem_i2p);
    }
}

void *Processthread(void *data)
{
    int sum=0;
    while(1)
    {
        sem_wait(&sem_i2p);
        sem_wait(&sem_i2p);
        sum=a+b;
        printf("Sum = %d\n",sum);
        sem_post(&sem_p2i);

    }
}

int main(int argc, char const *argv[])
{
    sem_init(&sem_i2p,0,1);
    sem_init(&sem_p2i,0,1);
    pthread_create(&process,NULL,Processthread,NULL);
    pthread_create(&input,NULL,Inputthread,NULL);
    pthread_join(input,NULL);
    pthread_join(process,NULL);

    return 0;
}

