import common.ListNode;

public class AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if(l1 == null && l2 == null) {
            return null;
        }

        ListNode head = new ListNode();
        ListNode pointer = head;
        int carry = 0;
        int current;
        while(l1 != null || l2 != null) {
            current = (l1 == null ? 0: l1.val) + (l2 == null ? 0: l2.val) + carry;
            carry = current / 10;
            current %= 10;

            pointer.next = new ListNode(current);
            pointer = pointer.next;
            if(l1 != null) l1 = l1.next;
            if(l2 != null) l2 = l2.next;
        }

        if(carry != 0) {
            pointer.next = new ListNode(1);
        }

        return head.next;
    }
}
