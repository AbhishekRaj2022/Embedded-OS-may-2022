#include<stdio.h>
#include"arith.h"

int main(int argc, char const *argv[])
{
    
    int output1=add(1000,2000);
    int output2=sub(1000,2000);
    int output3=mulp(1000,2000);
    int output4=div(1000,2000);
    printf("Addition of 1000 and 2000 : %d\nSubtraction of 1000 and 2000 : %d\nMultiplication of 1000 and 2000 : %d\nDivision of 1000 and 2000 : %d\n",output1,output2,output3,output4);
    return 0;
}
