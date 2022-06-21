#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;
     
    id=fork();
    
    if(id==0)
    {
        printf("This is the child \n");
        execl("./thread_demo","./thread_demo",NULL);

    }
    else
    {
        printf("This is the Parent \n");
        wait(NULL);
    }

    return 0;
}
