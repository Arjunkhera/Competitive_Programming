import java.util.ArrayDeque;
import java.util.Deque;
import java.util.function.Consumer;

public class SlidingWindowMaximum {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums.length == 0 || k <= 0) return new int[]{};
        if(k == 1) return nums;

        int[] result = new int[nums.length - k + 1];
        Deque<Integer> window = new ArrayDeque<>();

        Consumer<Integer> add = (index) -> {
            while (!window.isEmpty() && nums[window.peekFirst()] < nums[index]) window.pollFirst();
            window.addFirst(index);
        };

        for(int i = 0; i < k; i++) add.accept(i);
        result[0] = nums[window.peekLast()];

        for(int startIndex = 1; startIndex < nums.length - k + 1; startIndex++) {
            if(!window.isEmpty() && window.peekLast() < startIndex) window.pollLast();
            add.accept(startIndex + k - 1);
            result[startIndex] = nums[window.peekLast()];
        }

        return result;
    }
}
