import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.function.Consumer;
import java.util.function.Supplier;

public class SlidingWindowMedian {
    public double[] medianSlidingWindow(int[] nums, int k) {
        if(nums.length == 0 || k < 0 || k > nums.length) return new double[]{};

        Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        Queue<Integer> minHeap = new PriorityQueue<>();

        Supplier<Double> findMedian = () -> maxHeap.size() == minHeap.size()
                ? maxHeap.peek() + (minHeap.peek() - maxHeap.peek())/2.0
                : maxHeap.peek();
        Consumer<Integer> add = (num) -> {
            maxHeap.add(num);
            minHeap.add(maxHeap.poll());
            if(minHeap.size() > maxHeap.size()) {
                maxHeap.add(minHeap.poll());
            }
        };
        Consumer<Integer> delete = (num) -> {
            if(num <= findMedian.get()) {
                maxHeap.remove(num);
                if(minHeap.size() > maxHeap.size()) {
                    maxHeap.add(minHeap.poll());
                }
            } else {
                minHeap.remove(num);
                if(minHeap.size() < maxHeap.size() - 1) {
                    minHeap.add(maxHeap.poll());
                }
            }
        };

        double[] medians = new double[nums.length - k + 1];
        int j = 0;
        for(int i = 0; i < k; i++) {
            add.accept(nums[i]);
        }
        medians[j++] = findMedian.get();

        for(int i = k; i < nums.length; i++) {
            delete.accept(nums[i - k]);
            add.accept(nums[i]);
            medians[j++] = findMedian.get();
        }

        return medians;
    }
}
