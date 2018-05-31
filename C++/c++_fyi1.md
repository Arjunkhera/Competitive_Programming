### 1. Difference between methods and functions

**A method is on an object.**  
**A function is independent of an object.**

For Java, there are only methods.  
For C, there are only functions.    
For C++ it would depend on whether or not you're in a class.  

[Source](https://stackoverflow.com/questions/155609/difference-between-a-method-and-a-function)

### 2. Generating Random Numbers

```c++
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespaces std;

int main(){

  srand((unsigned)time(0));

  // gives a random number between 0 and 99
  int random = rand()%100;

  return 0;
}

```

[Source](https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c)

### 3. Understanding iterators

**What does an iterator do**  

An iterator is an object with syntax very much like a pointer. The following operations are defined for iterators:

1. get value of an iterator, int x = \*it;
2. increment and decrement iterators it1++, it2–;  
3. compare iterators by ‘!=’ and by ‘<’  
4. add an immediate to iterator it += 20; <=> shift 20 elements forward  
5. get the distance between iterators, int n = it2-it1;  

**[Important]**  
All the above operations are not supported by iterators. Iterators are broadly of five types, here is a take from a [ SO answer ](https://stackoverflow.com/questions/5211914/types-of-iterator-output-vs-input-vs-forward-vs-random-access-iterator) :

Iterator Category | Ability                         | Providers
----------------- | ------------------------------- | ----------------------------
Input iterator    | Reads forward                   | istream
Output iterator   | Writes forward                  | ostream, inserter
Forward iterator  | Reads/writes forward            | forward_list,          unordered_[multi]set, unordered_[multi]map
Bidirectional it. | Reads/writes forward/backward   | list, [multi]set, [multi]map
Random access it. | Reads/writes with random access | vector, deque string, array

Check [this](http://www.bogotobogo.com/cplusplus/stl3_iterators.php) or [this](http://www.cplusplus.com/reference/iterator/) for an in depth study of types   

**A note from topcoder**

Not all types of iterators provide all the potential functionality. In fact, there are so-called “normal iterators” and “random access iterators”. Simply put, normal iterators may be compared with ‘==’ and ‘!=’, and they may also be incremented and decremented. They may not be subtracted and we can not add a value to the normal iterator. Basically, it’s impossible to implement the described operations in O(1) for all container types  

Also, c.begin() == c.end() if and only if c is empty, and c.end() – c.begin() will always be equal to c.size(). (The last sentence is valid in cases when iterators can be subtracted, i.e. begin() and end() return random access iterators, which is not true for all kinds of containers.

A simple container's method using iterators to reverse the elements

```c++
template<typename T> void reverse_array(T *first, T *last) {
     if(first != last) {
          while(true) {
               swap(*first, *last);
               first++;
               if(first == last) {
                    break;
               }
               last--;
               if(first == last) {
                    break;
               }
          }
     }
}
```

### 4. Getting a float value from an integer division

The following would do the necessary  

```c++
double answer = static_cast<double>(a)/b;
```

[Source](https://stackoverflow.com/questions/15550708/c-wrong-result-of-mathematical-expression)
