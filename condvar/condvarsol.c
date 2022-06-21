// Conditional Variable Solution

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int event=0;
pthread_cond_t cond_var;
pthread_mutex_t mutex_var;

void *wait_init_thread(void *data)
{
    printf("Inside waiting thread\n");
    printf("Waiting thread : grabing lock\n");
    pthread_mutex_lock(&mutex_var);
    printf("Waiting thread : LOCKED\n");
    while(event!=1)
    {
        printf("Waiting thread : conditional waiting for event = 1\n");
        pthread_cond_wait(&cond_var,&mutex_var);
        printf("Waiting thread : event = 1\n");
    }
    printf("Waiting thread : Main functionality\n");
    pthread_mutex_unlock(&mutex_var);
    printf("Waiting thread : UNLOCKED\n");
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
    printf("Firing thread : UNLOCKED\n");
    pthread_cond_signal(&cond_var);

}


int main(int argc, char const *argv[])
{
    pthread_t wait_thread,fire_thread;
    pthread_cond_init(&cond_var,NULL);
    pthread_mutex_init(&mutex_var,NULL);
    pthread_create(&wait_thread,NULL,wait_init_thread,NULL);
    pthread_create(&fire_thread,NULL,fire_init_thread,NULL);
    pthread_join(wait_thread,NULL);
    pthread_join(wait_thread,NULL);
    pthread_mutex_destroy(&mutex_var);
    pthread_cond_destroy(&cond_var);

    return 0;
}
