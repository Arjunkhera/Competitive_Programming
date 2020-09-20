
### Questions :

### Subarray
1. [maximum sum](https://leetcode.com/problems/maximum-subarray/description/)
  - brute,kadane and divideConquer
2. [maximum product](https://leetcode.com/problems/maximum-product-subarray/description/)  
  - brute and
  - [kadane two pass - very simple](https://leetcode.com/problems/maximum-product-subarray/discuss/48302/2-Passes-scan-beats-99)
  - [dp : maintain pos and neg products](https://leetcode.com/problems/maximum-product-subarray/discuss/48261/Share-my-DP-code-that-got-AC/48395)
3. [flip subarray for max 1's](https://www.interviewbit.com/problems/flip/)
  - use a variation of kadane to solve

### Simple math
1. [minimum steps in an infinite grid](https://www.interviewbit.com/problems/min-steps-in-infinite-grid/)
  - O(n) solution
2. [add one to a number](https://leetcode.com/problems/plus-one/description/)
  - O(n) solution
3. [maximum absolute difference](https://www.interviewbit.com/problems/maximum-absolute-difference/)
  - aka maximize manhatten difference
  - [check this for solution](https://www.geeksforgeeks.org/maximum-absolute-difference-value-index-sums/)

### Using dp
1. []()

### Missing/Duplicates
1. [Missing number 1 to n](https://leetcode.com/problems/missing-number/)
  - just xor
2. [single duplicate in 1 to n+1](https://leetcode.com/problems/find-the-duplicate-number/description/)
  - use cycle detection technique for best solution
  - [all solutions](https://leetcode.com/problems/find-the-duplicate-number/solution/)
3. [one missing, one duplicate](https://www.interviewbit.com/problems/repeat-and-missing-number-array/)
  - very good tactice to solve, check handwritten notes for explanation

### Sliding window
1. [sliding window maximum](https://leetcode.com/problems/sliding-window-maximum/)
  - using deque with sliding window O(n)
  - using a multiset O(nlogk)  
2. [flip m zeros for max continuous 1's](https://www.careercup.com/question?id=5106425965576192)

### Miscellaneous  
1. [uniquePaths 1](https://leetcode.com/problems/unique-paths/description/)
  - dp to maintain history, O(m*n),O(m*n)-> space can be reduced to O(min(m,n))
2. [uniquePaths 2](https://leetcode.com/problems/unique-paths-ii/description/)
  - same as above,just dont update if an obstacle is present
