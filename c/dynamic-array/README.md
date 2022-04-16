# Dynamic arrays (or array list)

A dynamic array is the easiest method to implement a list using arrays that can change it's dimensions in memory relatively to the number of elements in it.

### Pro's
C has a useful native implementation to access a specific index of an array that is computationally efficient.

### Cons
Operations other than append and remove at the last available index can be much less efficient in a computational way, since they require shifting every following element to the next index and only then insert the element requested
The realloc() function may fail to find continuous memeory block on the heap that is sufficiently large, in the case of a very fragmented memory. Also realloc() is not efficient when it needs to shift the whole array to another point in memory.
These problems can be solved by using a liked list.