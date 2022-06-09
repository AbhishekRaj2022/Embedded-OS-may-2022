#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    pid_t ppid;

    pid = getpid();
    printf("Process ID pid : %d\n", pid);

    pid = getppid();
    printf("Process Parent ID pid : %d\n", ppid);

    return 0;
}