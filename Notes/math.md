
### Prime Numbers
[All about primes](https://www.geeksforgeeks.org/prime-numbers/)

####1. [Count Primes](https://leetcode.com/problems/count-primes/description/)
  - [range of solutions](https://leetcode.com/problems/count-primes/discuss/57614/Simple-16-ms10-line-C++-solution.-1.use-new-bool-array-2.-only-traverse-odd-numbers-3.count-and-sieve-at-the-same-time)
  - interviewbit prime sum question is similar, just need to find sum there

### Miscellaneous

####1. [find gcd](https://www.interviewbit.com/problems/greatest-common-divisor/)
  - use euclidean algorithm
####2. [rearrange array](https://www.interviewbit.com/problems/rearrange-array/)
  - O(n), O(1) : just arr[i] to arr[i] += (arr[arr[i]]%n)\*n;
  - [geeksforgeeks](https://www.geeksforgeeks.org/rearrange-given-array-place/)
####3. [implement power function](https://leetcode.com/problems/powx-n/description/)
  - best time O(logn) by working with powers of 2
  - [multiple solutions for interview](https://leetcode.com/problems/powx-n/discuss/19544/5-different-choices-when-talk-with-interviewers)
####4. [is this a power of a number](https://www.interviewbit.com/problems/power-of-two-integers/)
  - brute force your way to all possible combinations
  - [or check this out](https://stackoverflow.com/questions/38895208/interviewbitpower-of-two-integers#) and then look for the code in interviewbit folder
####5. [excel : column to number](https://leetcode.com/problems/excel-sheet-column-number/description/)
  - O(n) single traversal
####6. [excel : number to column](https://leetcode.com/problems/excel-sheet-column-title/description/)
  - works on the same principle as printing digits of a number, just a small change
  - [best explanation for n-1](https://leetcode.com/problems/excel-sheet-column-title/discuss/51404)
