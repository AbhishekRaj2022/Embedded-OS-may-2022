#include <stdio.h>
#include <pthread.h>
#include<stdlib.h>
#include<unistd.h>

int count =0;
pthread_mutex_t mutex_count;

pthread_t inc,dec;

void *Incdisplay(void *data)
{
    while(1)
    {
        pthread_mutex_lock(&mutex_count);
        count ++;
        sleep(10);
        printf("Increment thread : %d\n",count);
        pthread_mutex_unlock(&mutex_count);
    }
}



void *Decdisplay(void *data)
{
    while(1)
    {
        int res=0;
        pthread_mutex_trylock(&mutex_count);
        if(res==0)  //check if the lock is available
        {
            count --;
            printf("Decrement thread : %d\n",count);
            pthread_mutex_unlock(&mutex_count);
        }
        /*else
        {
            // Perform other functionalities
        }
        */
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
