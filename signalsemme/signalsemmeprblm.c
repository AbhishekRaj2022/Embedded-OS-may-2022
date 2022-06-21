// Signaling or Unsynchronization problem between threads

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int a,b;
pthread_t input,process;

void *Inputthread(void *data)
{
    while(1)
    {
        scanf("%d",&a);
        scanf("%d1",&b);
    }
}


void *Processthread(void *data)
{
    int sum=0;
    while(1)
    {
        sum=a+b;
        printf("Sum = %d\n",sum);
    }    
}

int main(int argc, char const *argv[])
{
    pthread_create(&process,NULL,Processthread,NULL);
    pthread_create(&input,NULL,Inputthread,NULL);
    pthread_join(input,NULL);
    pthread_join(process,NULL);

    return 0;
}

