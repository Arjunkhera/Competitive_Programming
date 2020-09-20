### Comparing int and string element

In a hurry, and you compare str[i] == 1 :(
Thats is a very common and irritating mistake cause thats always gonna return a
true value.

corrects way is as follows :
```c++
if(str[i] == '1')
```

### How to print a number in its binary representation

Use bitset,but remember that the size of bitset cannot be a variable, not even a const variable. It has to be a constant.

```c++
#include <iostream>
#include <bitset>

int main() {
    int a = -58, b = a>>3, c = -315;

    std::cout << "a = " << std::bitset<8>(a)  << std::endl;
    std::cout << "b = " << std::bitset<8>(b)  << std::endl;
    std::cout << "c = " << std::bitset<16>(c) << std::endl;
}
```

**But what if I want it to be a variable ?**  
You cannot, the only way out is to use dynamic bitset from boost library or vector<bool>.  [Source](https://stackoverflow.com/questions/40938609/use-a-variable-to-set-the-size-of-a-bitset)

### Unable to input a line ?

Using getline and still not able to input a line . The reason is a previously lying "\n" in the input buffer left by, for example a cin statement. So to deal with this, place a cin.ignore() statement to clear the buffer and voila the problem is solved.

```c++
#include<iostream>
using namespace std;

int main(){
  string str;
  int n;

  cin>>n;
  cin.ignore();
  getline(cin,str);
  cout<<str;
  return 0;
}
```

### what is the difference between "a" and 'a' ?

Look at this [stackoverflow anwer](https://stackoverflow.com/questions/11279126/what-is-the-difference-between-a-and-a)


Though here is a just of that :
'a' is a character literal. It's of type char, with the value 97 on most systems (the ASCII/Latin-1/Unicode encoding for the letter a).

"a" is a string literal. It's of type const char[2], and refers to an array of 2 chars with values 'a' and '\0'. In most, but not all, contexts, a reference to "a" will be implicitly converted to a pointer to the first character of the string.

**Also : A string literal is of type const char[], but string library defines a type std::string. C++ inherited string literals from C, but std::string is specific to C++**

### converting character arrays to strings and vice versa ?

**[char array to string](https://stackoverflow.com/questions/8960087/how-to-convert-a-char-array-to-a-string)**
```c++
char arr[] = "arjun";

string str(arr);
//or
str = arr;
```

**[string to char array](https://stackoverflow.com/questions/7352099/stdstring-to-char)**
```c++
std::string str = "string";
const char *cstr = str.c_str();

// neccessarily want char *
std::string str = "string";
char *cstr = new char[str.length() + 1];
strcpy(cstr, str.c_str());
// do stuff
delete [] cstr;
```

### Declaring and passing a variable sized 2d array

[Source : Stackoverflow](https://stackoverflow.com/questions/5508341/create-a-2d-array-with-variable-sized-dimensions)

```c++
int** array;
array = new int*[width];
for (int i = 0;i<width;i++)
    array[i] = new int[height];

// and to free the memory

for (int i = 0;i<width;i++)
    delete[] array[i];
delete[] array;

// passing to a function

void func(int ** array){
  // here it behave like any 2d array
  cout<<array[i][j];
}

// function call

func(array);
```

### Using Templates and issues with them

[Using in header](https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file)

**Note** : If we include template classes or functions for a header file, then in order to separate implementation and interface we need to come up with a new method.
