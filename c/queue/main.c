#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX 8

int main(int argc,  char** argv) {
    queue fifo = init(MAX);

    int enqueue(fifo, 8);
    int enqueue(fifo, 4);
    int enqueue(fifo, 0);
    int enqueue(fifo, 0);
    int dequeue(fifo, 4);
}