#include <stdio.h>
#include <pthread.h>
#include<stdlib.h>

int count =0;

pthread_t inc,dec;

void *Incdisplay(void *data)
{
    while(1)
    {
    count ++;
    printf("Increment thread : %d\n",count);
    }
}



void *Decdisplay(void *data)
{
    while(1)
    {
    count --;
    printf("Decrement thread : %d\n",count);
    }
}


int main(int argc, char const *argv[])
{

    pthread_create(&inc,NULL,Incdisplay,NULL);
    pthread_create(&dec,NULL,Decdisplay,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);

    return 0;
}
