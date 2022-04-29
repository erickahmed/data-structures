#include <stdio.h>
#include <stdlib.h>
#include "singly-linked-list.h"

#define FIRST_ELEM  9

int main(int argc,  char** argv)
{
    NODE *sLink = alloc_node(FIRST_ELEM);
    debug_list(sLink);

    insert_node(sLink, 4);
    debug_list(sLink);
    insert_node(sLink, 2);
    debug_list(sLink);
    insert_node(sLink, 0);
    debug_list(sLink);
    insert_node(sLink, -7);
    debug_list(sLink);

    delete_node(sLink);
    debug_list(sLink);

    tail_delete(sLink);
    debug_list(sLink);
    insert_tail_node(sLink, -2);
    debug_list(sLink);

    index_insert_node(sLink, 5, 2);
    debug_list(sLink);

    delete_list(sLink);
    debug_list(sLink);

}