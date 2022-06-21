#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_barrier_t dev_barr_count;

void *serial_thread(void *data)
{
    printf("Serial Init : started\n");
    sleep(8);   //Emulating serial port init. Not ot be used in real life.
    printf("Serial Init : Finished\n");
    pthread_barrier_wait(&dev_barr_count);
    printf("Serial : Main Functionality\n");

}

void *ether_thread(void *data)
{
    printf("Ethernet Init : started\n");
    sleep(10);   //Emulating Ethernet port init. Not ot be used in real life.
    printf("Ethernet Init : Finished\n");
    pthread_barrier_wait(&dev_barr_count);
    printf("Ethernet : Main Functionality\n");

}

void *lcd_thread(void *data)
{
    printf("LCD Init : started\n");
    sleep(2);   //Emulating LCD port init. Not ot be used in real life.
    printf("LCD Init : Finished\n");
    pthread_barrier_wait(&dev_barr_count);
    printf("LCD : Main Functionality\n");

}
// when value of barrier becomes 0, it means all the threads are ready.
int main(int argc, char const *argv[])
{
    pthread_t serial,ether,lcd;
    pthread_barrier_init(&dev_barr_count,NULL,3);
    pthread_create(&serial,NULL,serial_thread,NULL);
    pthread_create(&ether,NULL,ether_thread,NULL);
    pthread_create(&lcd,NULL,lcd_thread,NULL);
    pthread_join(serial,NULL);
    pthread_join(ether,NULL);
    pthread_join(lcd,NULL);
    pthread_barrier_destroy(&dev_barr_count);
    return 0;
}

