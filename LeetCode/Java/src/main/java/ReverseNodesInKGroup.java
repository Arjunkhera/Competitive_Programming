import common.ListNode;

public class ReverseNodesInKGroup {
    public ListNode reverseKGroup(ListNode head, int k) {
        int reverseCount;
        ListNode newHead = new ListNode();
        newHead.next = head;
        ListNode previous = newHead;
        ListNode current = head;
        ListNode tail = previous;
        ListNode temp;

        while(true) {
            reverseCount = k;

            if(current == null) break;

            while (reverseCount > 0 && current != null) {
                temp = current.next;
                current.next = tail;
                tail = current;
                current = temp;
                reverseCount--;
            }

            if(reverseCount == 0) {
                temp = previous.next;
                temp.next = current;
                previous.next = tail;
                tail = previous = temp;
            } else {
                while(tail != previous) {
                    temp = tail.next;
                    tail.next = current;
                    current = tail;
                    tail = temp;
                }
                break;
            }
        }

        return newHead.next;
    }
}
