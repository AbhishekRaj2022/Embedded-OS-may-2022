#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>           /* For O_* constants */
#include <mqueue.h>
#include <time.h>

#define MAX_SIZE 128
struct mq_attr mqattr;
mqd_t mqdes;
char *msg_ptr="DESD\n";
int main(int argc, char const *argv[])
{
    mqattr.mq_flags=0;  //ignored if mq_open() is done
    mqattr.mq_maxmsg=4; //the no. elements or length of queue
    mqattr.mq_msgsize=MAX_SIZE; //maximum size of each element
    mqattr.mq_curmsgs=0;    //is there any current msg inside queue

    mqdes=mq_open("/dataqueue",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR,&mqattr);

    if(mqdes==-1)
    {
        perror("Error in Creating MSG_QUEUE");
        exit(EXIT_FAILURE);
    }

    mq_send(mqdes,msg_ptr,sizeof(msg_ptr),0);
    close(mqdes);
    return 0;
}

