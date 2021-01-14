import common.TreeNode;

public class MaximumDifferenceBetweenNodeAndAncestor {
    public int recursion(TreeNode root, int rangeMin, int rangeMax) {
        if(root == null) return rangeMax - rangeMin;

        rangeMin = Math.min(rangeMin, root.val);
        rangeMax = Math.max(rangeMax, root.val);

        int sumLeft = recursion(root.left, rangeMin, rangeMax);
        int sumRight = recursion(root.right, rangeMin, rangeMax);
        return Math.max(sumLeft, sumRight);
    }

    public int maxAncestorDiff(TreeNode root) {
        if(root == null) return 0;
        return recursion(root, root.val, root.val);
    }
}
