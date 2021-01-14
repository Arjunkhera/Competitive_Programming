import common.TreeNode;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class BinaryTreeRightSideView {
    class Pair {
        public TreeNode node;
        public int level;

        public Pair() {};
        public Pair(TreeNode node, int level)  {
            this.node = node;
            this.level = level;
        }
    }

    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> view = new ArrayList<>();

        if(root == null) return view;

        int level = 0;
        Queue<Pair> store = new ArrayDeque<>();
        store.offer(new Pair(root, level));
        while(!store.isEmpty()) {
            Pair current = store.poll();
            if(current.level == level) {
                view.add(current.node.val);
                level++;
            }

            if(current.node.right != null) {
                store.offer(new Pair(current.node.right, current.level + 1));
            }
            if(current.node.left != null) {
                store.offer(new Pair(current.node.left, current.level + 1));
            }

        }

        return view;
    }
}
