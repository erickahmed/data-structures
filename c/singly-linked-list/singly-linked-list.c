#include <stdio.h>
#include <stdlib.h>
#include "singly-linked-list.h"

static struct node *alloc_node(int elem) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));

    if(newNode != NULL) {
        newNode->elem = elem;
        newNode->next = NULL;
    }
    return newNode;
}

static struct node *search_node(struct node *L, unsigned int i) {
    while(i-- > 0 && L != NULL)
        L = L->next;
    return L;
}

static int insert_node(struct node *L, int elem) {
    if(L == NULL) return 1;
    else {
        struct node *tmp = alloc_node(elem);

        if(tmp != NULL) {
            tmp->next = L->next;
            L->next = tmp;
        }
        return tmp == NULL;
    }
}

static int delete_node(struct node *L) {
    if(L == NULL || L->next == NULL) return 0;
    else {
        struct node *tmp = L->next;
        L->next = tmp->next;
        free(tmp);
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

static int insert_head_node(struct node *L, int elem) {
    if(L == NULL) return 0;
    else {
        struct node *tmp = alloc_node(elem);

        if(tmp != NULL) {
            tmp->next = L;
            L = tmp;
        }
        return tmp == NULL;
    }
}

static int insert_tail_node(struct node *L, int elem) {
    if(L == NULL) return 0;
    else if(is_empty(L)) return insert_head_node(L, elem);
    else {
        struct node *tmp = L;

        while(tmp->next != NULL)
            tmp = tmp->next;

        return insert_node(tmp, elem);
    }
}

static int index_insert_node(struct node *L, int elem, unsigned int index) {
    if(index == 0) return insert_head_node(L, elem);
    else return insert_node(search_node(L, index--), elem);
}

static int head_delete(list *L) {
    if(L == NULL) return 1;
    else {
        struct node *tmp = *L;

        *L = (*L)->next;
        free(tmp);
        return 0;
    }
}

static int tail_delete(list *L) {
    if(is_empty(L)) return 1;
    else if((*L)->next == NULL) return head_delete(L);
    else {
        struct node *tmp = *L;

        while(tmp->next->next != NULL)
            tmp = tmp->next;

        return delete_node(tmp);
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