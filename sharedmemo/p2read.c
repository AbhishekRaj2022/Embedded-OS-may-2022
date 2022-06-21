#include<stdio.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int *mapped_SM=NULL;

int main(int argc, char const *argv[])
{
    int shmfd;

    //Creating Shared Memory 
    shmfd=shm_open("/mysharedmemo",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
    if(-1==shmfd)
    {
        perror("Error in creating shared memory\n");
        return EXIT_FAILURE;
    }

    //Providing size of the shared memory
    ftruncate(shmfd,sizeof(int));
    //printf("Afer truncate\n");

    // Maping the SM to Address Spaces
    mapped_SM=(int *)mmap(NULL,sizeof(int), PROT_READ | PROT_WRITE ,MAP_SHARED,shmfd,0);
    // NULL-> giving OS rights to give address to memory
    // sizeof(int)->space for the SM
    // Protection // visibility to other processes
    // 0 -> giving the starting address of the shared memory
    //printf("Afer mapping\n");

    while(1)
    {
        printf("%d\n",*mapped_SM);
    }

    close(shmfd);
    return 0;
}
