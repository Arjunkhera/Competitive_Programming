import common.ListNode;

import java.util.List;

public class RotateList {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null) return null;

        ListNode current = head;
        int length = 0;
        while(current != null) {
            length += 1;
            current = current.next;
        }

        k %= length;
        ListNode forward = head;
        current = head;
        while(k >0) {
            forward = forward.next;
            k--;
        }
        while(forward.next != null) {
            current = current.next;
            forward = forward.next;
        }

        forward.next = head;
        ListNode newHead = current.next;
        current.next = null;
        return newHead;
    }
}
