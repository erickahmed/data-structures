#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define NULL_INDEX -1

queue init(unsigned int n) {
    queue tmp = {0, NULL_INDEX, NULL_INDEX, NULL};

    tmp.data = (int *)malloc(n*sizeof(int));
    if(tmp.data != NULL) tmp.size = n;

    return tmp;
}

void clear(queue *Q) {
    if(Q != NULL) {
        free(Q->data);
        Q->data = NULL;
        Q->head = NULL_INDEX;
        Q->tail = NULL_INDEX;
        Q->size = 0;
    }
}

int is_empty(queue *Q) {
    return Q == NULL || Q->head == NULL_INDEX || ((Q->tail + 1) % Q->size == Q->head);
}

int enqueue(queue *Q, int elem) {
    if(Q == NULL) return 1;
    else if(is_empty(Q)) Q->tail = Q->head = 0;
    else Q->tail = ((Q->tail + 1) % Q->size);

    Q->data[Q->tail] = elem;
    return 0;
}

int dequeue(queue *Q, int *elem) {
    if(is_empty(Q) || elem == NULL) return 1;
    else {
        *elem = Q->data[Q->head];

        if(Q->head == Q->tail) Q->head = Q->tail = NULL_INDEX;
        else Q->head = (Q->head + 1) % Q->size;

        return 0;
    }
}

int front(queue *Q, int *elem) {
    if(is_empty(Q) || elem == NULL) return 1;
    else {
        *elem = *Q->data[Q->head];
        return 0;
    }
}

void debug_queue(queue *S) {
    printf("Queue: [");
    int *dat = *S->data - S->size;

    if(*dat == NULL) {
        printf("[ %d \n", dat);
    } else {
        printf("[ %d ", dat);
        *dat++;
    }
    while(*dat != NULL) {
        printf("-> %d ", *dat);
        *dat++;
    }
    printf("]\n");
}