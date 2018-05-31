## Reference

[ Topcoder : Power up with STL ](https://www.topcoder.com/community/data-science/data-science-tutorials/power-up-c-with-the-standard-template-library-part-1/)  

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

vector<int> v2(v1);
vector<int> v3(v.begin(), v.end()); // v3 equals to v2

// Constructing a vector from an array
int arr[] = {1,2,3,4,5};
vector<int> first(arr,arr+5);

int data[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
vector<int> primes(data, data+(sizeof(data) / sizeof(data[0])));

// reversing a segment of an array
int data[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
reverse(data+2, data+6); // the range { 5, 7, 9, 11 } is now { 11, 9, 7, 5 };

```

## Traversing a vector

**Implementation provided**

1. using normal iteration with size function
2. using iterators

**Remarks**
1. size() is unsigned, which may sometimes cause problems. Define macros, something like sz(C) that returns size of C as ordinal signed int.
2. It’s not a good practice to compare v.size() to zero if you want to know whether the container is empty. You’re better off using empty() function :

```c++
bool is_nonempty_notgood = (v.size() >= 0); // Try to avoid this
bool is_nonempty_ok = !v.empty();
```

This is because not all the containers can report their size in O(1), and you definitely should not require counting all elements in a double-linked list just to ensure that it contains at least one.

**Some notes for traversing a vector**


```c++
vector<int> v;

// ...

// Traverse all container, from begin() to end()
for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
     *it++; // Increment the value iterator is pointing to
}

```

**NOTE**
Use ‘!=’ instead of ‘<’, and ‘empty()’ instead of ‘size() != 0′ — for some container types, it’s just very inefficient to determine which of the iterators precedes another.

## Error worthwhile noticing

```c++
void f(const vector<int>& v) {
      for(
           vector<int>::iterator it = v.begin(); // hm... where’s the error?..
           // ...
      // ...
    )
}

```

Passing a const reference to a vector and 

```c++
void f(const vector<int>& v) {
      int r = 0;
      // Traverse the vector using const_iterator
      for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
           r += (*it)*(*it);
      }
      return r;
 }
```


## Standard templates for STL

Provided from topcoder article, though I would reccommend against using them frequently,
however they can be used as a reference or a quick lookup in case you are forgetting stuff.

```c++


```
