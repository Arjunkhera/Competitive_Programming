import java.util.ArrayDeque;
import java.util.Deque;

public class LongestSubarrayWithAbsoluteDiff {
    public int longestSubarray(int[] nums, int limit) {
        if(nums.length == 0 || limit <= 0) return 0;

        int length = 0;
        int startIndex = 0;
        Deque<Integer> maxQueue = new ArrayDeque<>();
        Deque<Integer> minQueue = new ArrayDeque<>();
        for(int endIndex = 0;  endIndex < nums.length; endIndex++) {
            int element = nums[endIndex];
            while(!maxQueue.isEmpty() && maxQueue.peekLast() < element)
                maxQueue.pollLast();
            maxQueue.addLast(element);

            while(!minQueue.isEmpty() && minQueue.peekLast() > element)
                minQueue.pollLast();
            minQueue.addLast(element);

            while(startIndex < endIndex && maxQueue.peekFirst() - minQueue.peekFirst() > limit) {
                if(nums[startIndex] == maxQueue.peekFirst()) maxQueue.pollFirst();
                if(nums[startIndex] == minQueue.peekFirst()) minQueue.pollFirst();
                startIndex++;
            }

            length = Math.max(length, endIndex - startIndex + 1);
        }

        return length;
    }
}
