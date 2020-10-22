import common.ListNode;

public class RemoveNthNodeFromEndOfList {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null) return null;

        ListNode back = head;
        ListNode front = head;
        while(front != null && n > 0) {
            front = front.next;
            n--;
        }

        if(front == null) {
            if(n == 0) {
                return head.next;
            } else {
                return head;
            }
        }

        while(front.next != null) {
            back = back.next;
            front = front.next;
        }
        back.next = back.next.next;
        return head;
    }
}
