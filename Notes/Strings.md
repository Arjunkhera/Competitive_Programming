
Algorithmic Complexities written in the following order
[Time Complexity, Space Complexity]

1. [Integer to Roman](https://leetcode.com/problems/integer-to-roman/description/)
2. [Roman to Integer](https://leetcode.com/problems/roman-to-integer/description/)
3. [Longest Common Prefix : 5 Methods](https://leetcode.com/problems/longest-common-prefix/description/)
4. [Longest Palindromic Substring : 5 Methods](https://leetcode.com/problems/longest-palindromic-substring/description/)
5. [Count and Say](https://leetcode.com/problems/count-and-say/description/)
6. [Length of Last Word](https://leetcode.com/problems/length-of-last-word/description/)
7. [Zig Zag conversion](https://leetcode.com/problems/zigzag-conversion/description/)
8. [Reverse string](https://leetcode.com/problems/reverse-string/description/)
9. Substring Matching -> Pattern(m) Searching
    - bruteforce [n*m,n]
    - kmp [n+m,m]
      - [youtube](https://www.youtube.com/watch?v=GTJr8OvyEVQ)
      - [geeksforgeeks](https://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/)
      - [topcoder](https://www.topcoder.com/community/data-science/data-science-tutorials/introduction-to-string-searching-algorithms/)
10. [atoi - convert string to integer, lots of edge cases](https://leetcode.com/problems/string-to-integer-atoi/description/)       
11 Valid number -> very tough
    - [DFA solution](https://leetcode.com/problems/valid-number/discuss/23725/C++-My-thought-with-DFA)
12. [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/description/)
13. [Valid Palindrome 2 : 3 methods, brute, itertaive or greedy->all easy](https://leetcode.com/problems/valid-palindrome-ii/description/)
14. [Shortest Palindrome->hard](https://leetcode.com/problems/shortest-palindrome/description/)
  - bruteforce
  - kmp
15. [Longest Substring without repeating characters]()https://leetcode.com/problems/longest-substring-without-repeating-characters/description/  
  - bruteforce O(n^3)
  - sliding window O(n) -> 2n
  - sliding window optimized O(n) -> n

16. Longest Substring with 2 unique characters : Locked on leetcode :/
17. Longest Substring with k unique characters : Locked on leetcode :/

18. [Substring with concatenation of words : very tough](https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/)
  - [without sliding window O(n-k)*k ](https://www.geeksforgeeks.org/find-starting-indices-substrings-string-s-made-concatenating-words-listl/)
  - [with sliding window](https://www.programcreek.com/2014/06/leetcode-substring-with-concatenation-of-all-words-java/)

19. [group anagram](https://leetcode.com/problems/group-anagrams/description/)
  - sort + hash map O(nklogk)
  - sort by frequency + hash map O(nk)
