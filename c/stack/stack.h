#ifndef STACK_H
#define STACK_H

typedef struct stack {
    unsigned int size;
    unsigned int last;
    int *data;
} stack;

stack init(unsigned int n);
void clear(stack *S);
int is_empty(stack *S);
int is_full(stack *S);
int push(stack *S, int elem);
int pop(stack *S);
int top(stack *S, int *elem);
void debug_stack(stack *S);

#endif