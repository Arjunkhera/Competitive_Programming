public class InsertIntoBinarySearchTree {

    public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
    }


    public TreeNode insertIntoBST(TreeNode root, int val) {
        if(root == null) return new TreeNode(val);

        TreeNode newRoot = root;
        TreeNode previous = root;
        while(root != null) {
            previous = root;
            root = root.val > val ? root.left : root.right;
        }

        TreeNode newNode = new TreeNode(val);
        if(previous.val > val) {
            previous.left = newNode;
        } else {
            previous.right = newNode;
        }

        return newRoot;
    }
}
