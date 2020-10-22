import common.ListNode;

public class MergeTwoSortedLists {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null && l2 == null) return null;
        ListNode newHead = new ListNode();
        ListNode previous = newHead;

        while(l1 != null && l2 != null) {
            if(l1.val < l2.val) {
                previous.next = l1;
                previous = l1;
                l1 = l1.next;
            } else if(l2.val < l1.val) {
                previous.next = l2;
                previous = l2;
                l2 = l2.next;
            } else {
                previous.next = l1;
                previous = l1;
                l1 = l1.next;
                previous.next = l2;
                previous = l2;
                l2 = l2.next;
            }
        }

        if(l1 != null) previous.next = l1;
        if(l2 != null) previous.next = l2;
        return newHead.next;
    }
}
