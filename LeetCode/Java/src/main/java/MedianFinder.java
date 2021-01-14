import java.util.PriorityQueue;
import java.util.Queue;

public class MedianFinder {
    Queue<Integer> maxHeap;
    Queue<Integer> minHeap;

    public MedianFinder() {
        maxHeap = new PriorityQueue<>((o1, o2) -> -1*Integer.compare(o1, o2));
        minHeap = new PriorityQueue<>();
    }

    public void addNum(int num) {
        maxHeap.add(num);
        minHeap.add(maxHeap.poll());
        if(minHeap.size() > maxHeap.size()) {
            maxHeap.add(minHeap.poll());
        }
    }

    public double findMedian() {
        return maxHeap.size() == minHeap.size()
                ? maxHeap.peek() + (minHeap.peek() - maxHeap.peek())/2.0
                : maxHeap.peek();
    }
}
