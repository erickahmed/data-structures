/*
    DYNAMIC ARRAY:
    A dynamically allocated array that doubles its size every time there's not
    enough space in the allocated memory: it creates a new array double the dimention of
    the old array and deletes the old one.
    Modify INIT_SIZE or ELEM to change the array dimensions and the final allocated memory
*/

#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

#define INIT_SIZE 1     // array initial size
#define TOT_ELEM 999    // elements to store dynamically
#define BIG_O

static unsigned long len = 0;
static unsigned long cap = INIT_SIZE;

int main(int argc,  char** argv)
{
    ARRAY dyn_arr = alloc_array(cap);

    /*  #ifdef BIG_O
        int test_array[99] = {65, 84, 39, 70, 49, 47, 28, 29, 60, 35, 69, 78, 63, 98, 0, 63, 0, 47, 65, 84, 99, 89, 58, 37, 79, 32, 97, 75, 72, 14, 18, 83, 84, 6, 89, 11, 47, 1, 0, 51, 93, 35, 47, 51, 45, 83, 91, 18, 24, 27, 2, 48, 86, 40, 60, 76, 63, 16, 22, 39, 47, 81, 4, 55, 99, 60, 47, 67, 0, 66, 7, 35, 28, 36, 0, 0, 8, 39, 88, 16, 60, 80, 86, 58, 9, 69, 13, 9, 70, 53, 98, 66, 59, 49, 98, 94, 55, 38, 82};

        for(int i=0; i<99; i++) {
            append_array(&dyn_arr, i);
            debug_array(&dyn_arr);
        }
    #endif
    #ifndef BIG_O*/


    append_array(&dyn_arr, 4);
        debug_array(&dyn_arr);
    append_array(&dyn_arr, 2);
        debug_array(&dyn_arr);
    append_array(&dyn_arr, 0);
        debug_array(&dyn_arr);
            append_array(&dyn_arr, 4);
        debug_array(&dyn_arr);
    append_array(&dyn_arr, 2);
        debug_array(&dyn_arr);
        pop_array(&dyn_arr);
        debug_array(&dyn_arr);
                pop_array(&dyn_arr);
        debug_array(&dyn_arr);
                pop_array(&dyn_arr);
        debug_array(&dyn_arr);
    append_array(&dyn_arr, 0);
        debug_array(&dyn_arr);
            append_array(&dyn_arr, 4);
        debug_array(&dyn_arr);
    append_array(&dyn_arr, 2);
        debug_array(&dyn_arr);
    append_array(&dyn_arr, 0);
        debug_array(&dyn_arr);

    return 0;
}