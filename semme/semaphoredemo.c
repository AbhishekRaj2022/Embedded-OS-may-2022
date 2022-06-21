// Race Condition Solution Using Mutual Exclusion by Semaphore

#include <stdio.h>
#include <pthread.h>
#include<stdlib.h>
#include<semaphore.h>

int count =0;
sem_t MEcount;
pthread_t inc,dec;

void *Incdisplay(void *data)
{
    while(1)
    {
        sem_wait(&MEcount);
        count ++;
        printf("Increment thread : %d\n",count);
        sem_post(&MEcount);
    }
}



void *Decdisplay(void *data)
{
    while(1)
    {
        sem_wait(&MEcount);
        count --;
        printf("Decrement thread : %d\n",count);
        sem_post(&MEcount);
    }
}


int main(int argc, char const *argv[])
{
    sem_init(&MEcount,0,1);
    pthread_create(&inc,NULL,Incdisplay,NULL);
    pthread_create(&dec,NULL,Decdisplay,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);
    sem_destroy(&MEcount);

    return 0;
}
