#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

unsigned int n = 8;

int main(int argc,  char** argv)
{
    stack lifo = init(n);

    debug_stack(&lifo);
    push(&lifo, 3);
    debug_stack(&lifo);
    push(&lifo, 6);
    debug_stack(&lifo);
    push(&lifo, 9);
    debug_stack(&lifo);

    pop(&lifo);
    debug_stack(&lifo);
}