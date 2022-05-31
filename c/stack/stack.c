#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack init(unsigned int n){

    stack tmp = {0, 0, NULL};
    clear(&tmp);

    tmp.data = (int *)calloc(n, sizeof(int));
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

int push(stack *S, int elem) {
    if(is_full(S)) return 1;
    else {
        S->data[S->last++] = elem;
        return 0;
    }
}

int pop(stack *S) {
    if(is_empty(S) || &S->last == NULL) return 1;
    else {
        int tmp = S->last--;
        //free(&S->last);
        S->last = S->data[tmp - 1];

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

/* TODO: Debug the debug pls*/
void debug_stack(stack *S) {
    printf("Stack: [");
    int i = 0;

    if(&S->data[i] == NULL) {
        printf("[ %d \n", S->data[i]);
    } else {
        printf("[ %d ", S->data[i]);
        i++;
    }
    while(i < S->size) {
        printf("-> %d ", S->data[i]);
        i++;
    }
    printf("]\n");
}