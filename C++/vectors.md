
## General Advice

**Containers**
Any time you need to operate with many elements you require some kind of container. In native C   (not C++) there was only one type of container: the array.  

## Constructing a vector

```c++

// empty vector
vector<int> first;

// vector with a size of 10 and elements initialized as zero
vector<int> first(10);

// an array of 10 empty integer vectors
vector<int> arr[10];

// vector with a size of 10 and elements initialized as "battlefield"
vector<string> second("battlefield");

// 2-d vector of size n*m with default elements as -1
// important : the space between the inner vector and outer vecotor is a must
// this is wrong : vector<vector<int>>
vector< vector<int> > matrix(n, vector<int>(m,-1));

// both v2 and v3 are same
vector<int> v2 = v1;
vector<int> v3(v1);

```

## Traversing a vector

**Implementation provided**

1. using normal iteration with size function
2. using iterators

**Remarks**
1. size() is unsigned, which may sometimes cause problems. Define macros, something like sz(C) that returns size of C as ordinal signed int.
2. It’s not a good practice to compare v.size() to zero if you want to know whether the container is empty. You’re better off using empty() function:

```c++
bool is_nonempty_notgood = (v.size() >= 0); // Try to avoid this
bool is_nonempty_ok = !v.empty(); 
```

This is because not all the containers can report their size in O(1), and you definitely should not require counting all elements in a double-linked list just to ensure that it contains at least one.

## Modifying a vector

```c++



```
