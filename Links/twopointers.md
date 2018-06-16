1. [Sort Colors](https://leetcode.com/problems/sort-colors/)
  - Count all occurences - two passes
  - three pointers - single pass
2. [Remove Duplicates](https://leetcode.com/problems/remove-element/description/)
  - two pointers - single pass
3. [Remove Duplicates 2](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/)
  - two pointers - single pass
4. [Remove element](https://leetcode.com/problems/remove-element/description/)  

2sum and 3 sums can have varities  such as  
a. Find if solution exists   
b. Find all solutions   
c. Presence of duplicates in above two

duplicates can be handled easily, check this [leetcode solution](https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C++-solution-around-50ms-O(N*N)-with-explanation-and-comments) for details.     

5. [2 sum](https://leetcode.com/problems/two-sum/description/)
  - [geeksforgeeks](https://www.geeksforgeeks.org/?p=484)
  - m1 brute O(n^2)
  - m2 sorting O(nlogn)
  - m3 hashing O(n)
6. [3 sum hard,v.imp]()
  - [geeksforgeeks - unique](https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/)
  - [geeksforgeeks - duplicate]()
  - m1 brute O(n^3)
  - m2 sorting O(n^2)
  - m3 hashing O(n^2)
7. [3 sum closest](https://leetcode.com/problems/3sum-closest/description/)
  - m1 brute O(n^3)
  - m2 sorting O(n^2) [leetcode solution](https://leetcode.com/problems/3sum-closest/discuss/7883/C++-solution-O(n2)-using-sort)
8. [Intersection of two arrays](https://leetcode.com/problems/intersection-of-two-arrays/description/)
  - sort and two pointers O(nlogn)
  - use two set O(m+n)
  - use binary search O(nlogn) in sorting method
9. [Intersection of two arrays](https://leetcode.com/problems/intersection-of-two-arrays-ii/discuss/82281/Two-C++-solutions:-hashtable-and-sort+binary-search.-Time-and-space-complexity-analyzed.)
  - check the leetcode question for further constraints
10. [Array 3 pointers : good question](https://www.interviewbit.com/problems/array-3-pointers/)  
  - brute force O(n^3)
  - use three pointers, minimize at each step, and stop when out of bound cause no way left to minimize, as any other increment only widens the already max gap O(m+n+k)
11. [Maximum consecutive 1's : modifications allowed m](https://www.interviewbit.com/problems/max-continuous-series-of-1s/)
  - sliding concept O(n+m)
  - [geeksforgeeks](https://www.geeksforgeeks.org/find-zeroes-to-be-flipped-so-that-number-of-consecutive-1s-is-maximized/)
12. [minimize ablsolute difference](https://www.careercup.com/question?id=14805690)
  - same as array 3 pointers
13. [Find pair with given differece - assuming unsorted](https://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/)  
  - brute O(n^2)
  - sort(nlogn) + bsearch all elements(nlogn)
  - sort(nlogn) + [linear search using two pointers(n)](https://www.interviewbit.com/problems/diffk/)
14. [Valid Triangles](https://leetcode.com/problems/valid-triangle-number/description/)
  - brute O(n^3)
  - sort then search O(n^2)
  - same approach as 3 closest question, gives much better results
