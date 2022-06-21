#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;
    char arg[2][40],cmd[40];
    
    while(strcmp(cmd,"exit"))
    {
        printf("MY SHELL : # ");
        scanf("%s",cmd);

        id=fork();

        if(id==0)
        {
            if(strcmp(cmd,"ls")==0)
            execl("/usr/bin/ls","/usr/bin/ls",NULL);
            
            else if(strcmp(cmd,"cp")==0)
            {
                scanf("%s%s",&arg[0][40],&arg[1][40]);
                execl("/usr/bin/cp",*arg,NULL);
            }
            else if(strcmp(cmd,"touch")==0)
            execl("/usr/bin/touch","/usr/bin/touch",NULL);

            else if(strcmp(cmd,"which")==0)
            execl("/usr/bin/which","/usr/bin/which",NULL);

        }
        else
        {
            wait(NULL);
        }
    }
    return 0;
}
