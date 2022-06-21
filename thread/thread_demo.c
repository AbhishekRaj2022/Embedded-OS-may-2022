#include <stdio.h>
#include <pthread.h>

pthread_t tid;

void *display(void *data)
{
    printf("This is thread\n");
}

int main(int argc, char const *argv[])
{
    printf("Before thread creation\n");
    pthread_create(&tid,NULL,display,NULL);
    pthread_join(tid,NULL);
    printf("After thread creation\n");
    return 0;
}
