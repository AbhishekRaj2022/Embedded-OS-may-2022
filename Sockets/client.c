#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<linux/in.h>
#include<unistd.h>

int cfd;

//giving client server details so no need for client struct
struct sockaddr_in saddr;

int len;
unsigned char buff[1024];

int main(int argc, char const *argv[])
{
    // Forming a socket and specifying its attributes
    cfd=socket(AF_INET,SOCK_STREAM,0);

    // Initializing the structure variables with IPv4 adr and port no. along with family
    saddr.sin_family= AF_INET;
    saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    saddr.sin_port= htons(5678);

    connect(cfd,(struct sockaddr *)&saddr,sizeof(struct sockaddr_in));
    read(cfd,buff,1024);                    // Reading from the server
    printf("Server Sent : %s\n",buff);
    write(cfd,"Hello from Client\n",18);

    close(cfd);

    return 0;
}

