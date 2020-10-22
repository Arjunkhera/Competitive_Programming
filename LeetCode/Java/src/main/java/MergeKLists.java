import common.ListNode;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class MergeKLists {
    public ListNode mergeKLists(ListNode[] lists) {
            if(lists == null || lists.length == 0) return null;

            int size = lists.length;
            Queue<ListNode> store = new PriorityQueue<>(size, Comparator.comparingInt(listNode -> listNode.val));
            for (ListNode list : lists) {
                if(list != null) {
                    store.add(list);
                }
            }

            ListNode head = new ListNode();
            ListNode current = head;
            while(!store.isEmpty()) {
                current.next = store.poll();
                current = current.next;

                if(current.next != null) {
                    store.add(current.next);
                }
            }

            return head.next;
        }
}
