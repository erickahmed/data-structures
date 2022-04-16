# Singly Linked List

A singly linked list works like an array but with an important difference: the memory in which the list resides does not have to be contiguous, because every element points to the next one forming a chain of elements.

### Pro's

Efficient use of memory because it can be allocated in a fragmentated way and during execution only the memory needed to represent the actual list is used.
Insertion and deletion are computationally efficient since the processor does not need to re-organize the entire data structure.

### Cons

The only (efficient) way to access any n-th element of the list is to start from element n=0 and go trough every element until you find the n-th element.
This is also the only way in which you may go through the list, and for this reason the doubly linked list is the next step of the singly linked list.
It causes memory overhead, because every element has a pointer to the next one.