
## Pairs  

A simple structure of a pair   

```c++
template<typename T1, typename T2> struct pair {
     T1 first;
     T2 second;
};
```

Some examples of pair in action  

```c++
pair<string, pair<int,int> > P;
string s = P.first; // extract string
int x = P.second.first; // extract first int
int y = P.second.second; // extract second int
```

**Important**  
The great advantage of pairs is that they have built-in operations to compare themselves. Pairs are compared first-to-second element. If the first elements are not equal, the result will be based on the comparison of the first elements only; the second elements will be compared only if the first ones are equal. The array (or vector) of pairs can easily be sorted by STL internal functions.  

For example, if you want to sort the array of integer points so that they form a polygon, it’s a good idea to put them to the vector< pair<double, pair<int,int> >, where each element of vector is { polar angle, { x, y } }. One call to the STL sorting function will give you the desired order of points.

[diff b/w set,mutliset,unordered_set and unordered_multiset](https://www.geeksforgeeks.org/difference-set-multiset-unordered_set-unordered_multiset/)
