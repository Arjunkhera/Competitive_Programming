## Basic Data Structures :

### 1.Arrays

Let size of array be n.
1. Accessing Time: O(1) [This is possible because elements
                      are stored at contiguous locations]   
2. Search Time:   O(n) for Sequential Search:
               O(log n) for Binary Search [If Array is sorted]
3. Insertion Time: O(n) [The worst case occurs when insertion
                     happens at the Beginning of an array and
                     requires shifting all of the elements]
4. Deletion Time: O(n) [The worst case occurs when deletion
                     happens at the Beginning of an array and
                     requires shifting all of the elements]

### 2. Linked Lists

Some common types
1. Singly Linked Lists
2. Doubly Linked Lists
3. Circular Linked Lists

Given n elements,  
1. Accessing time of an element : O(n)
2. Search time of an element : O(n)
3. Insertion of an Element : O(1) [If we are at the position
                                where we have to insert
                                an element]
4. Deletion of an Element : O(1) [If we know address of node
                               previous the node to be
                               deleted]

### 3. Stacks

1. Insertion : O(1)
2. Deletion :  O(1)
3. Access Time : O(n) [Worst Case]
4. Insertion and Deletion are allowed on one end.

**We can always remove recursion with the help of stacks**

### 4. Queues :

1. Insertion : O(1)
2. Deletion  : O(1)
3. Access Time : O(n) [Worst Case]
