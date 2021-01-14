import common.TreeNode;

public class BinaryTreeTilt {
    Integer tiltSum = 0;

    public Integer find(TreeNode node) {
        if(node == null) return 0;

        Integer leftSum = find(node.left);
        Integer rightSum = find(node.right);
        this.tiltSum += Math.abs(leftSum - rightSum);
        return leftSum + rightSum + node.val;
    }

    public int findTilt(TreeNode root) {
        find(root);
        return this.tiltSum;
    }
}
