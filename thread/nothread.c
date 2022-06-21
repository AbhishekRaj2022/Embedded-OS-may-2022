#include <stdio.h>
#include <pthread.h>

void display(void)
{
    printf("This is thread\n");
}

int main(int argc, char const *argv[])
{
    printf("Before thread creation\n");
    display();
    printf("After thread creation\n");
    return 0;
}