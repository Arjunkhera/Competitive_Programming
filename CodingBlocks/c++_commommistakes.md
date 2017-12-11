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
