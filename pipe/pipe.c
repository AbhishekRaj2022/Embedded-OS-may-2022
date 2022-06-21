#include<stdio.h> 
 #include <fcntl.h>              /* Obtain O_* constant definitions */ 
 #include <unistd.h> 
  
 # define MAX 5 
  
 int main(int argc, char const *argv[]) 
 { 
     char buff[MAX]; 
     pid_t id; 
     int fd[2]; 
     pipe(fd);   //pipe should be declared before fork. Always. 
     // fd[0] ==> reading 
     // fd[0] ==> writing 
  
     // Creating two processes 
     id=fork(); 
     if(id==0) 
     { 
         //child Process 
         close(fd[1]);   //the writing end of the pipe is not used so close it. 
         printf("Inside Child Process\n"); 
         printf("Reading from Child : "); 
         read(fd[0],buff,MAX); 
         printf("%s\n",buff); 
     } 
     else if(id>0) 
     { 
         //Parent Process 
         close(fd[0]);   //the reading end of the pipe is not used so close it. 
         printf("Inside Parent Process\n"); 
         printf("Writing from Parent\n\n"); 
         write(fd[1],"DESD\n",MAX); 
     } 
     else 
     { 
         perror("Forking Unsucessfull"); 
     } 
  
     close(fd[0]); 
     close(fd[1]); 
     return 0; 
 }
