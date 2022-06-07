#include <stdio.h>
#include <stdlib.h>

int a;
int b = 10;

int main(int argc, char const *argv[])
{
    int result = 0;
    int *p = NULL;

    p = (int*) malloc(sizeof(int));

    return 0;
}

int add(int a, int b)
{
    return a + b;
}