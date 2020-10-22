import common.ListNode;

import java.util.List;

public class SwapNodesInPairs {
    public ListNode swapPairs(ListNode head) {
        if(head == null) return null;

        ListNode newHead = new ListNode();
        newHead.next = head;
        ListNode previous = newHead;
        ListNode current = head;
        ListNode swapNext = head.next;

        while(current != null && swapNext != null) {
            current.next = swapNext.next;
            swapNext.next = current;
            previous.next = swapNext;

            previous = current;
            current = current.next;
            if(current != null) swapNext = current.next;
        }

        return newHead.next;
    }
}
