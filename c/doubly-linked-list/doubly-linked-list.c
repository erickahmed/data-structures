#include <stdio.h>
#include <stdlib.h>
#include "doubly-linked-list.h"

static struct node *alloc_node(int elem) {
    struct node *tmp = (struct node *) malloc(sizeof(struct node));

    if(tmp != NULL) {
        tmp->elem = elem;
        tmp->next = NULL;
        tmp->prev = NULL;
    }
    return tmp;
}

static struct node *search_node(struct node *L, unsigned int i) {
    while(i-- > 0 && L != NULL)
        L = L->next;
    return L;
}

static int insert_node(struct node *L, int elem) {
    if(L == NULL) return 1;
    else {
        struct node *tmp = malloc(elem);

        if(tmp != NULL) {
            tmp->next = L->next;
            tmp->prev = L;
            L->next   = tmp;
        } if(tmp->next != NULL) {
            tmp->next->prev = tmp;
    }

    return tmp == NULL;
    }
}

static int delete_node(struct node *L) {
    if(L != NULL) return 1;
    else {
        if(L->next == NULL) L->next->prev = L->prev;
        if(L->prev != NULL) L->prev->next = L->next;
        free(L);

        return 0;
    }
}

static int is_empty(list *L) {
    return (L == NULL) || (*L == NULL);
}

static int is_in_list(list *L, int elem) {
    if(is_empty(L)) return 0;
    else {
        struct node *tmp = *L;

        while(tmp != NULL && tmp->elem != elem)
            tmp = tmp->next;

        return tmp != NULL;
    }
}

void delete_list(list *L) {
    if(L != NULL && *L != NULL) {
        delete_list(&(*L)->next);
        free(*L);
        *L = NULL;
    }
}

void debug_list(list L) {
    printf("List: [");

    if(L->next == NULL) {
        printf("[ %d ]\n", L->elem);
    } else {
        printf("[ %d ", L->elem);
        L->next = L->next->next;
    }
    while(L->next != NULL) {
        printf("-> %d ", L->elem);
        L->next = L->next->next;
    }

    if(L->next == NULL) {
        printf("]\n");
    }
}
