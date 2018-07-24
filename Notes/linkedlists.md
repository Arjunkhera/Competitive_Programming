### Why Linked List?

Arrays can be used to store linear data of similar types, but arrays have following limitations.
1. The size of the arrays is fixed: So we must know the upper limit on the number of elements in advance. Also, generally, the allocated memory is equal to the upper limit irrespective of the usage.
2. Inserting a new element in an array of elements is expensive, because room has to be created for the new elements and to create room existing elements have to shifted.

Advantages over arrays
1. Dynamic size
2. Ease of insertion/deletion

Drawbacks:
1. Random access is not allowed. We have to access elements sequentially starting from the first node. So we cannot do binary search with linked lists.
2. Extra memory space for a pointer is required with each element of the list.
3. Arrays have better cache locality that can make a pretty big difference in performance.

### Questions :

1. Which sorting algorithm to prefer for linked list ?  
Both Merge sort and Insertion sort can be used for linked lists. The slow random-access performance of a linked list makes other algorithms (such as quicksort) perform poorly, and others (such as heapsort) completely impossible. Since worst case time complexity of Merge Sort is O(nLogn) and Insertion sort is O(n^2), merge sort is preferred. See following for implementation of merge sort using Linked List.

2. Reversing a linked list
Both iterative and recursive take
a. Time completely  O(n)
b. Space completely O(1)

### Questions :

### Sorting
1. [merge sort](https://leetcode.com/problems/sort-list/description/)
  - some variations can ask for a constant space solution, then you will have to change from recursion to iteration [ very tough ]
  - [awesome iterative solution](https://leetcode.com/problems/sort-list/discuss/46712/Bottom-to-up(not-recurring)-with-o(1)-space-complextity-and-o(nlgn)-time-complextity)
2. [insertion sort](https://leetcode.com/problems/insertion-sort-list/description/)

### Subarray
1. [partition the list](https://leetcode.com/problems/partition-list/description/)
2.


### Good Reads
1. [Stanford : Complete LL coverage](http://cslibrary.stanford.edu/103/LinkedListBasics.pdf)
