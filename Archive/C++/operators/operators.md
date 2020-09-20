#### Operator precedence and associativity

[Table of precedence](http://www.learncpp.com/cpp-tutorial/31-precedence-and-associativity/)

**Pow works only for floats, can give precision errors for ints. Use exponential squaring to write your own function. Check raisingpower.cpp for code**

#### Explicitly changing types for operation : use static_cast<>

```c++
std::cout << "int / int = " << x / y << "\n";
std::cout << "double / int = " << static_cast<double>(x) / y << "\n";
std::cout << "int / double = " << x / static_cast<double>(y) << "\n";
std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << "\n";
```
#### Negative numbers in division and modulus

```c++
int a = -5;
int b = 2;
int c = a/b;
int d = a%b;
```

**Prior to C++11**  
Answer of c and d was dependant on compiler

**Post C++11**  
c is truncated towards zero,so c = -2  
d is given sign of lhs of %, here that of a, so d = -1;

Check negativedivmod.cpp for code  

#### Increment and Decrement Operators

Just remember how the following code works
```c++
int x = 5, y = 5;
std::cout << x << " " << y << '\n';                     // 5 5
std::cout << ++x << " " << --y << '\n'; // prefix       // 6 4
std::cout << x << " " << y << '\n';                     // 6 4
std::cout << x++ << " " << y-- << '\n'; // postfix      // 6 4
std::cout << x << " " << y << '\n';                     // 7 3
```

#### Problems with side effects : here due to Increment and Decrement Operators

The following is undefined
```c++
int add(int x, int y){ return x + y; }

int main(){
    int x = 5;
    int value = add(x, ++x); // is this 5 + 6, or 6 + 6?  It depends on what order your compiler evaluates the function arguments in

    std::cout << value; // value could be 11 or 12, depending on how the above line evaluates!
    return 0;
}
```

And so is this
```c++
int main(){
    int x = 1;
    x = x++;
    std::cout << x;

    return 0;
}
```

**Don’t use a variable that has a side effect applied to it more than once in a given statement. If you do, the result may be undefined.**

#### sizeof

#### comma operator
The comma operator allows you to evaluate multiple expressions wherever a single expression is allowed. The comma operator evaluates to its rightmost operand.

**avoid using it at all costs,except and only in for loops**  
why ? very low precedence, even less than =   
```c++
z = (a, b); // evaluate (a, b) first to get result of b, then assign that value to variable z.
z = a, b; // evaluates as "(z = a), b", so z gets assigned the value of a, and b is discarded.
```

Also, take note
```c++
int sum = add(x, y); // this comma is not the comma operator
int x(3), y(5); // this comma is not the comma operator either
```

#### conditional operator

1. It should always have both the expression evaluate to same type
```c++
std::cout << (x != 5 ? x : "x is 5"); // won't compile
```
2. Has very low precedence,be careful while using
```c++
std::cout << ((x > y) ? x : y); // correct

// << has greater precedence, so output is 1 or 0 depending on the evaluation
std::cout << (x > y) ? x : y; // incorrect
```

#### handling floating point errors

Rounding errors crop up when we use in floats. Here is an example
```c++
double d1(100 - 99.99); // should equal 0.01
double d2(10 - 9.99); // should equal 0.01

if (d1 == d2)
 std::cout << "d1 == d2" << "\n";
else if (d1 > d2)
 std::cout << "d1 > d2" << "\n";
else if (d1 < d2)
 std::cout << "d1 < d2" << "\n";
```
Output will not be d1 == d2 as expected   
Comparing floating point values when the difference is large is not an issue, however for smaller values we need to write a function to adapt to this

[Check this out for better explanation](http://www.learncpp.com/cpp-tutorial/35-relational-operators-comparisons/)

Code in comparingfloats.cpp  
