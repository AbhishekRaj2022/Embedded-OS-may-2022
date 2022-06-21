#include <stdio.h>
#include <pthread.h>
#include<stdlib.h>

int count =0;
pthread_mutex_t mutex_count;

pthread_t inc,dec;

void *Incdisplay(void *data)
{
    while(1)
    {
        pthread_mutex_lock(&mutex_count);
        count ++;
        printf("Increment thread : %d\n",count);
        pthread_mutex_unlock(&mutex_count);
    }
}



void *Decdisplay(void *data)
{
    while(1)
    {
        pthread_mutex_lock(&mutex_count);
        count --;
        printf("Decrement thread : %d\n",count);
        pthread_mutex_unlock(&mutex_count);
    }
}


int main(int argc, char const *argv[])
{
    pthread_mutex_init(&mutex_count,NULL);
    pthread_create(&inc,NULL,Incdisplay,NULL);
    pthread_create(&dec,NULL,Decdisplay,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);
    pthread_mutex_destroy(&mutex_count);

    return 0;
}
