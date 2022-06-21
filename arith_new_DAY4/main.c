#include<stdio.h>
#include"arith.h"


int main(int argc, char const *argv[])
{
    int result=0,subres=0;
    printf("Arith Demo\n");
    subres=sub(20,10);
    result= add(10,20);
    printf("Addition of two numbers 10,20 : %d\n\n",result);
    printf("Subtraction of two numbers 20,10 : %d\n\n",subres);
    
    return 0;
}
