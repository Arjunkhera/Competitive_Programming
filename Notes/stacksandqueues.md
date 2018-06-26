
1. [Special Stack](https://leetcode.com/problems/min-stack/description/)
  - [geeksforgeeks : space O(n)](https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/)
  - [geeksforgeeks : space O(1)](https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/)

2. [Largest Rectangle Area](https://leetcode.com/problems/largest-rectangle-in-histogram/description/)
  - brute force O(n^2)
  - [divide and conquer O(nlogn) using segment trees](https://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-set-1/)
  - [using stacks O(n)]()

3. [Sliding window maximum](https://leetcode.com/problems/sliding-window-maximum/description/)  
  - brute force O(k*n)
  - use self balancing bst O(nlogk)
  - using a dequeue O(n) -> 2n to be precise
  - [geeksforgeeks](https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/)

In the dequeue solution, the only case that can be hard to pick is when removing the front elements for being out of window. Just think, any element smaller than front will have have to be introduced after front element was added, otherwise it would have been popped for being smaller. Hence popping for out of bounds needs to be done only from front and not back  
