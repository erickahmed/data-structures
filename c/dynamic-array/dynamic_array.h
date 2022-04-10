#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <stdbool.h>

typedef struct dynamic_array {
    int *items;
    unsigned size;
    unsigned max_index;
} ARRAY;

ARRAY alloc_array(unsigned int size);
void  realloc_array(ARRAY *arr, unsigned int size);
void  free_array(ARRAY arr);
bool  is_empty(ARRAY arr);
bool  is_full(ARRAY arr);
void  append_array(ARRAY *arr, int item);
void  pop_array(ARRAY *arr);
void  insert_array(ARRAY *arr, int index, int item);
void  modify_array(ARRAY *arr, int index, int item);
void  debug_array(ARRAY *arr);

#endif