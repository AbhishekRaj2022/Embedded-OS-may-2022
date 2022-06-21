# include<stdio.h>
# include<sys/types.h>
# include<unistd.h>


int main(int argc, char const *argv[])
{
    pid_t pid;
    pid_t ppid;
    pid=getpid();
    printf("Process ID : %d\n",pid);
    
    ppid=getppid();
    printf("Parent Process ID : %d\n\n",ppid);
    return 0;
}


