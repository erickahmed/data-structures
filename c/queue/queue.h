#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue {
    unsigned int size;
    struct node *head;
    struct node *tail;
    int *data;
} queue;

queue init(unsigned int n);
void clear(queue *Q);
int is_empty(queue *Q);
int is_full(queue *Q);
int enqueue(queue *Q, int elem);
int dequeue(queue *Q, int *elem);
int front(queue *Q, int *elem);

#endif