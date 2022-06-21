// Conditional Variable problem ==> Deadlock if waiting thread starts first.

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int event=0;
pthread_mutex_t mutex_var;

void *wait_init_thread(void *data)
{
    printf("Inside waiting thread\n");
    printf("Waiting thread : grabing lock\n");
    pthread_mutex_lock(&mutex_var);
    printf("Waiting thread : LOCKED\n");
    while(event!=1)
    {

    }
    printf("Waiting thread : waiting for event = 1\n");
    pthread_mutex_unlock(&mutex_var);

    //printf("Waiting thread : Init\n");
}


void *fire_init_thread(void *data)
{
    printf("Inside Firing thread\n");
    printf("Firing thread : grabing lock\n");
    pthread_mutex_lock(&mutex_var);
    printf("Firing thread : LOCKED\n");
    event=1;
    printf("Firing thread : Event =1 done !\n");
    pthread_mutex_unlock(&mutex_var);

    //printf("Waiting thread : Init\n");
}


int main(int argc, char const *argv[])
{
    pthread_t wait_thread,fire_thread;
    pthread_mutex_init(&mutex_var,NULL);
    pthread_create(&wait_thread,NULL,wait_init_thread,NULL);
    pthread_create(&fire_thread,NULL,fire_init_thread,NULL);
    pthread_join(wait_thread,NULL);
    pthread_join(wait_thread,NULL);
    pthread_mutex_destroy(&mutex_var);
    return 0;
}
