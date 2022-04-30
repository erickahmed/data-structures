# (Doubly Linked) Circular List

A circular list is much similiar to a linked list but with a key difference: the last element points to the first (and in the case of a doubly linked circular list, the first element's previous pointer points to the last element).

### Pro's

The main advantage is that you don't need to start from the beginning of the list, rather you could start from the middle of it or any other point you may want.

### Cons

Same memory overhead problems as for non-circular linked lists.
The only way to access an element in a random point of the list is to start any n-th element and iterate through every next or previous element until you find the one you were looking for.
You can't use NULL to check the end of the list since it's circular and any of the pointers points to the NULL value.