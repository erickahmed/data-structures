#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

typedef struct node {
    int elem;
    struct node *next;
    struct node *prev;
} node;

typedef struct node *list;

static struct node *alloc_node(int elem);
static struct node *search_node(struct node *L, unsigned int i);
static int insert_node(struct node *L, int elem);
static int delete_node(struct node *L);
static int is_empty(list *L);
static int is_inlist(list *L, int elem);
void delete_list(list *L);
void debug_list(list L);

#endif