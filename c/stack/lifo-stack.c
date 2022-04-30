#include <stdio.h>
#include <stdlib.h>
#include "lifo-stack.h"

stack init(unsigned int n){
    stack tmp = {0, 0, NULL};

    tmp.data = (int *)malloc(n+sizeof(int));
    if(tmp.data != NULL) tmp.size = n;
    return tmp;
}

void clear(stack *S) {
    if(S != NULL) {
        free(S->data);
        S->data = NULL;
        S->last = 0;
        S->size = 0;
    }
}

int is_empty(stack *S) {
    return S == NULL || S->last == 0;
}

int is_full(stack *S) {
    return S == NULL || S->last == S->size;
}

int push(stack *S, int *elem) {
    if(is_full(S)) return 1;
    else {
        S->data[S->last++] = elem;
        return 0;
    }
}

int pop(stack *S, int *elem) {
    if(is_empty(S) || elem == NULL) return 1;
    else {
        *elem = S->data[S->last-- -1];
        return 0;
    }
}

int top(stack *S, int *elem) {
    if(is_empty(S) || elem == NULL) return 1;
    else {
        *elem = S->data[S->last -1];
        return 0;
    }
}
