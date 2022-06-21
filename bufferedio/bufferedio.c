#include<stdio.h>

int main(int argc, char const *argv[])
{
    // will invoke only one write system call ==> Buffer is first collected then pushed
    printf("Hello ");
    printf("World ");

    // will invoke two write system call
    printf("Hello \n"); //buffer is collected and then first pushed
    printf("World ");   //next buffer is created and then pushed


    return 0;
}
