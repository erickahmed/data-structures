#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

unsigned int n = 8;

int main(int argc,  char** argv)
{
    stack lifo = init(n);

    push(&lifo, 3);
    push(&lifo, 6);
    push(&lifo, 9);

    pop(&lifo);
}