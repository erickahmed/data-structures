/*
    DYNAMIC ARRAY:
    A dynamically allocated array list that doubles its size every time there's not
    enough space in the allocated memory: it creates a new array double the dimensions of
    the old array.
*/

#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

#define INIT_SIZE 1     // array initial size

int main(int argc,  char** argv)
{
    // create array
    ARRAY dyn_arr = alloc_array(INIT_SIZE);

    // check if array is empty
    //is_empty(dyn_arr);

    // append 3 elements
    append_array(&dyn_arr, 4);
    debug_array(&dyn_arr);
    append_array(&dyn_arr, 2);
    debug_array(&dyn_arr);
    append_array(&dyn_arr, 0);
    debug_array(&dyn_arr);
    append_array(&dyn_arr, 69);
    debug_array(&dyn_arr);
    append_array(&dyn_arr, 6);
    debug_array(&dyn_arr);
    append_array(&dyn_arr, 6);
    debug_array(&dyn_arr);
    append_array(&dyn_arr, 6);
    debug_array(&dyn_arr);

    // modify 1 element
    modify_array(&dyn_arr, 5, 9);
    debug_array(&dyn_arr);

    // modify 1 element
    insert_array(&dyn_arr, 4, 111);
    debug_array(&dyn_arr);

    // delete the last element
    remove_last_elem_array(&dyn_arr);
    debug_array(&dyn_arr);

    // check if array is full
    //is_full(dyn_arr);

    return 0;
}