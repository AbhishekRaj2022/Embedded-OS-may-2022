#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<linux/in.h>
#include<unistd.h>

int sfd;
int cfd;
struct sockaddr_in saddr;
struct sockaddr_in caddr;
int len;
unsigned char buff[1024];

int main(int argc, char const *argv[])
{
    // Forming a socket and specifying its attributes 
    sfd=socket(AF_INET,SOCK_STREAM,0);

    // Initializing the structure variables with IPv4 adr and port no. along with family
    saddr.sin_family= AF_INET;
    saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    saddr.sin_port= htons(5678);


    // Binding the socket with server details in structure
    bind(sfd,(struct sockaddr *)&saddr,sizeof(struct sockaddr_in));
    // Setting server to listen for clients
    listen(sfd,10); // 10 ==> Max length of queue of pending connections 

    len = sizeof(struct sockaddr_in);
    cfd=accept(sfd,(struct sockaddr *)&caddr , &len);   

    write(cfd,"Hello from Server \n",19);    //writing to the client
    read(cfd,buff,1024);                    // Reading from the client
    printf("Client Sent : %s\n",buff);

    close(sfd);
    close(cfd);

    return 0;
}

