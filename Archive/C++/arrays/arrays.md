#### Cannot use variables to declare fixed sized arrays

```c++
// using a non-const variable
int length;
std::cin >> length;
int array[length]; // Not ok -- length is not a compile-time constant!

// using a runtime const variable
int temp = 5;
const int length = temp; // the value of length isn't known until runtime, so this is a runtime constant, not a compile-time constant!
int array[length]; // Not ok
```
