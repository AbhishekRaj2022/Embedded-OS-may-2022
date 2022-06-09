#include <stdio.h>
#include "arith.h"

int main(int argc, char const *argv[])
{
    int result = 0;

    printf("Arith Demo\n");

    result = add(10,20);
    printf("Addition Result: %d\n", result);

    result = sub(10,20);
    printf("Subtraction Result: %d\n", result);

    return 0;
}
