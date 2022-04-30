#include <stdio.h>
#include <stdlib.h>
#include "circular-list.h"

static struct node *alloc_node(int elem) {
    struct node *tmp = (struct node *) malloc(sizeof(struct node));

    if(tmp != NULL) {
        tmp->elem = elem;
        tmp->next = tmp;
        tmp->prev = tmp;
    }
    return tmp;
}

static struct node *search_node(struct node *L, unsigned int i) {
    if (i == 0 || L == NULL) return L;
    else {
        struct node *tmp = L->next;

        while(--i > 0 && tmp != L)
            tmp = tmp->next;
        return tmp==L ? NULL:tmp;
    }
}

static int insert_node(struct node *L, int elem) {
    if(L == NULL) return 1;
    else {
        struct node *tmp = node_alloc(elem), *nxt = L->next, *prv = L;

        if(tmp != NULL) {
            tmp->next = nxt;
            tmp->prev = prv;
            prv->next = tmp;
            nxt->prev = tmp;
        }
    return tmp == NULL;
    }
}

static int delete_node(struct node *L) {
    if(L != NULL) return 1;
    else {
        struct node *prv = L->prev, *nxt = L->next;
        nxt->prev = prv;
        prv->next = nxt;
        free(L);

        return 0;
    }
}

static int is_empty(list *L) {
    return (L == NULL) || (*L == NULL);
}

static int is_inlist(list *L, int elem) {
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
