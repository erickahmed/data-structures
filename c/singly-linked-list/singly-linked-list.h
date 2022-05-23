#ifndef SINGLY_LIKED_LIST_H
#define SINGLY_LIKED_LIST_H

typedef struct node{
    int elem;
    struct node *next;
} NODE;

typedef struct node *list;

static struct node *alloc_node(int elem);
static struct node *search_node(struct node *L, unsigned int i);
static int insert_node(struct node *L, int elem);
static int delete_node(struct node *L);
static int insert_head_node(struct node *L, int elem);
static int insert_tail_node(struct node *L, int elem);
static int index_insert_node(struct node *L, int elem, unsigned int index);
static int is_empty(list *L);
static int is_in_list(list *L, int elem);
static int head_delete(list *L);
static int tail_delete(list *L);
void delete_list(list *L);
void debug_list(list L);

#endif