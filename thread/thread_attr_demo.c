#include <stdio.h>
#include <pthread.h>

pthread_t tid;
pthread_attr_t attr;

void *display(void *data)
{
    printf("This is thread\n");
}

int main(int argc, char const *argv[])
{
    pthread_attr_init(&attr);
    printf("Before thread creation\n");
    pthread_create(&tid,&attr,display,NULL);
    pthread_join(tid,NULL);
    pthread_attr_destroy(&attr);
    printf("After thread creation\n");
    return 0;
}
