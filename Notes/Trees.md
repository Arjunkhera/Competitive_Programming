### Common Terminology ?



### Applications of Tree's ?

1. Manipulate hierarchical data.
2. Make information easy to search (see tree traversal).
3. Manipulate sorted lists of data.
4. As a workflow for compositing digital images for visual effects.
5. Router algorithms
6. Form of a multi-stage decision-making (see business chess).


### Good Reads
1. [Light intro](https://www.cs.cmu.edu/~adamchik/15-121/lectures/Trees/trees.html)
2. [All in one : a heavy read](http://liacs.leidenuniv.nl/~deutzah/DS/september28.pdf)

### Questions :

1. [Inorder traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)
  - iterative O(n),O(n) using stacks  
  - recursive O(n),O(n)
  - morris traversal O(n),O(1) [gfg](https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/)
  - **The above three can be made to work for pre and post order traversal also**
  - some useful reads [threaded tree](https://en.wikipedia.org/wiki/Threaded_binary_tree)
2. [Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)
  - using queue O(n),O(level with max nodes)
3. [Zig Zag level order ](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)
  - using two stacks
  - using a deque
4. [Maximum Depth of Tree][https://leetcode.com/problems/maximum-depth-of-binary-tree/description/]
  - Just remember to check whether they are asking for nodes or edges !
5. [Same tree](https://leetcode.com/problems/same-tree/description/)
6. [Symmetric tree](https://leetcode.com/problems/symmetric-tree/)
  - know both iterative(awesome solution) and recursive solutions
7. [Construct binary tree from inorder and preorder](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)
  - good question, try to understand both the iterative and recursive versions
8. [Construct binary tree from inorder and postorder](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/)
  - extremely similar to the above question
9. [making next level pointers ](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/)  
  - just a small change to levelorder traversal
10. [making next level pointers  2](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/)
 - same as above, only here the tree is not perfect, but levelorder solution works for all cases
 - the iterative solution uses O(1) space, keep that in mind for an optimised solution
