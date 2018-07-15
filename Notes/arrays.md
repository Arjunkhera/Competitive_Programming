
### Questions :

### Subarray
1. [maximum sum](https://leetcode.com/problems/maximum-subarray/description/)
  - brute,kadane and divideConquer
2. [maximum product](https://leetcode.com/problems/maximum-product-subarray/description/)  
  - brute and
  - [kadane two pass - very simple](https://leetcode.com/problems/maximum-product-subarray/discuss/48302/2-Passes-scan-beats-99)
  - [dp : maintain pos and neg products](https://leetcode.com/problems/maximum-product-subarray/discuss/48261/Share-my-DP-code-that-got-AC/48395)

### Simple math
1. [minimum steps in an infinite grid](https://www.interviewbit.com/problems/min-steps-in-infinite-grid/)
  - O(n) solution
2. [add one to a number](https://leetcode.com/problems/plus-one/description/)
  - O(n) solution

### Using dp
1. []()

####1. [sliding window maximum](https://leetcode.com/problems/sliding-window-maximum/)
  - using deque with sliding window O(n)
  - using a multiset O(nlogk)  

####2. [uniquePaths 1](https://leetcode.com/problems/unique-paths/description/)
  - dp to maintain history, O(m*n),O(m*n)-> space can be reduced to O(min(m,n))

####3. [uniquePaths 2](https://leetcode.com/problems/unique-paths-ii/description/)
  - same as above,just dont update if an obstacle is present
