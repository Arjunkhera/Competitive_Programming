
### To check whether a number is odd or even
```c++
if(x & 1) cout<<"Odd";
else cout<<"Even";
```

### To unset righmost set bit
```c++
n = n & n-1;
```

[Must read article on bit manipulations](http://www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know/)

1. [Single Number]()
2. [Single Number 2]()
3. [Count number of set bits](https://leetcode.com/problems/number-of-1-bits/description/)
  - Brute force O(number of bits in number)
  - Unsetting last set bit
  - [cool blog on this](https://articles.leetcode.com/number-of-1-bits/)
  - [geeksforgeeks-all solutions](https://www.geeksforgeeks.org/count-set-bits-in-an-integer/)
4. [Reverse bits of a number](https://leetcode.com/problems/reverse-bits/description/)
5. [Minimum XOR pair]()
  - brute force, all pairs O(n^2)
  - sort and single pass O(nlogn)
  - using tries O(n)
  - [geeksforgeeks](https://www.geeksforgeeks.org/minimum-xor-value-pair/)
6. [Maximum XOR pair](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/)
  -
