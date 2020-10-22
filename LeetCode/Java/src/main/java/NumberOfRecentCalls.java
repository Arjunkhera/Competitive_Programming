public class NumberOfRecentCalls {
    static class Node {
        int time;
        Node next;

        Node() {
        }

        Node(int time) {
            this.time = time;
            next = null;
        }
    }

    static class RecentCounter {
        Node head;
        Node tail;
        int length;

        public RecentCounter() {
            head = null;
            tail = null;
            length = 0;
        }

        public int ping(int t) {
            while (head != null && t - head.time > 3000) {
                head = head.next;

                length-=1;
            }

            if(tail != null) {
                tail.next = new Node(t);
                tail = tail.next;
            } else {
                tail = new Node(t);
            }

            head = (head == null) ? tail : head;
            length+=1;
            return length;
        }
    }

    /**
     * Your RecentCounter object will be instantiated and called as such:
     * RecentCounter obj = new RecentCounter();
     * int param_1 = obj.ping(t);
     */
    public static void main(String[] args) {
        RecentCounter recentCounter = new RecentCounter();
        System.out.println(recentCounter.ping(1));
        System.out.println(recentCounter.ping(100));
        System.out.println(recentCounter.ping(3001));
        System.out.println(recentCounter.ping(3002));
        System.out.println(recentCounter.ping(7002));
    }
}


