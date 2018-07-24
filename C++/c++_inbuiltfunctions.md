[good read](http://www.fredosaurus.com/notes-cpp/index.html)

## Commonly used c++ inbuilt functions

1. ####[swap](http://www.cplusplus.com/reference/utility/swap/)  
Exchange values of two objects
```c++
// swap algorithm example (C++11)
#include <iostream>     // std::cout
#include <utility>      // std::swap

int main () {

  int x=10, y=20;                  // x:10 y:20
  std::swap(x,y);                  // x:20 y:10

  int foo[4];                      // foo: ?  ?  ?  ?
  int bar[] = {10,20,30,40};       // foo: ?  ?  ?  ?    bar: 10 20 30 40
  std::swap(foo,bar);              // foo: 10 20 30 40   bar: ?  ?  ?  ?

  std::cout << "foo contains:";
  for (int i: foo) std::cout << ' ' << i;
  std::cout << '\n';

  return 0;
}
```

2. ####[range based for loop](https://docs.microsoft.com/en-in/cpp/cpp/range-based-for-statement-cpp)  
Executes statement repeatedly and sequentially for each element in expression.

```c++
// range-based-for.cpp  
// compile by using: cl /EHsc /nologo /W4  
#include <iostream>  
#include <vector>  
using namespace std;  

int main()   
{  
    // Basic 10-element integer array.  
    int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  

    // Range-based for loop to iterate through the array.  
    for( int y : x ) { // Access by value using a copy declared as a specific type.   
                       // Not preferred.  
        cout << y << " ";  
    }  
    cout << endl;  

    // The auto keyword causes type inference to be used. Preferred.  

    for( auto y : x ) { // Copy of 'x', almost always undesirable  
        cout << y << " ";  
    }  
    cout << endl;  

    for( auto &y : x ) { // Type inference by reference.  
        // Observes and/or modifies in-place. Preferred when modify is needed.  
        cout << y << " ";  
    }  
    cout << endl;  

    for( const auto &y : x ) { // Type inference by reference.  
        // Observes in-place. Preferred when no modify is needed.  
        cout << y << " ";  
    }  
    cout << endl;  
    cout << "end of integer array test" << endl;  
    cout << endl;  

    // Create a vector object that contains 10 elements.  
    vector<double> v;  
    for (int i = 0; i < 10; ++i) {  
        v.push_back(i + 0.14159);  
    }  

    // Range-based for loop to iterate through the vector, observing in-place.  
    for( const auto &j : v ) {  
        cout << j << " ";  
    }  
    cout << endl;  
    cout << "end of vector test" << endl;  

    // Printing keys and values of a map
    map <int, int> MAP({{1, 1}, {2, 2}, {3, 3}});
    for (auto i : MAP)
        cout << '{' << i.first << ", "
                  << i.second << "}\n";
}  
```

3. ####[range based for loop](https://docs.microsoft.com/en-in/cpp/cpp/range-based-for-statement-cpp)  
Executes statement repeatedly and sequentially for each element in expression.
