#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    printf("Before using exec\n");
    execl("/usr/bin/ls","/usr/bin/ls",NULL);    //loads the ls utility in RAM in place of the current ongoing process
    printf("After using exec\n");

    return 0;
}
