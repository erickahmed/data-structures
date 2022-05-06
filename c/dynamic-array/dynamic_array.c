#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dynamic_array.h"

#define INIT_SIZE 1     // array initial size

ARRAY alloc_array (unsigned int size) {
    ARRAY arr;

    arr.size = INIT_SIZE;
    arr.items = malloc(arr.size*sizeof(unsigned int));
    arr.max_index = 0;

    if(sizeof(arr.size) == 0) {
        perror("Memory not allocated\n");
        exit(0);
    }
    return arr;
}

void realloc_array(ARRAY *arr, unsigned int size) {
    if(arr->max_index >= arr->size) arr->size = 2*arr->max_index;
    else if(arr->max_index <= arr->size/2 && arr->size>2) arr->size = arr->size/2;

    arr->items = realloc(arr->items, size*(sizeof(int)));
    size = sizeof(arr);
    //TODO: garbage collection
}

void free_array(ARRAY arr) {
    free(arr.items);
}

bool is_empty(ARRAY arr) {
    if(arr.max_index == 0) return true;
}

bool is_full(ARRAY arr) {
    if(arr.max_index == arr.size) return true;
}

void append_array(ARRAY *arr, int item) {
    realloc_array(arr, arr->size);

    arr->items[arr->max_index] = item;
    arr->max_index++;
}

void remove_last_elem_array(ARRAY *arr) {
    arr->items[arr->max_index] = 0;
    arr->max_index--;

    realloc_array(arr, arr->size);
}

void insert_array(ARRAY *arr, int index, int item) {
    realloc_array(arr, arr->size+1);
    arr->max_index++;

    for(int i = arr->max_index; i >= index; --i) {
        arr->items[i+1] = arr->items[i];
    }

    arr->items[index] = item;
}

void modify_array(ARRAY *arr, int index, int item) {
    arr->items[index] = item;
}

void debug_array(ARRAY *arr) {
    printf("Last Index: %d; ", (arr->max_index)-1);
    printf("Bytes: %d; ", arr->size);

    printf("Array: [");
    printf("%d", arr->items[0]);
    for(int i = 1; i < arr->max_index; i++) {
        printf(", %d", arr->items[i]);
    }
    printf("] \n");
}