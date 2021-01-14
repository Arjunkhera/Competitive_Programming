import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;

public class LargestRectangleInHistogram {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        if(n == 0) return 0;

        int[] areas = heights.clone();
        Deque<Integer> store = new ArrayDeque<>();
        store.offerFirst(0);
        for(int i = 1; i < n; i++) {
            while(!store.isEmpty() && heights[i] < heights[store.peekFirst()]) {
                int index = store.pollFirst();
                areas[index] += (i-index-1)*heights[index];
            }
            store.offerFirst(i);
        }
        while(!store.isEmpty()) {
            int index = store.pollFirst();
            areas[index] += (n-index-1)*heights[index];
        }

        store.clear();
        store.offerFirst(n-1);
        for(int i = n-2; i >=0; i--) {
            while(!store.isEmpty() && heights[i] < heights[store.peekFirst()]) {
                int index = store.pollFirst();
                areas[index] += (index-i-1)*heights[index];
            }
            store.offerFirst(i);
        }
        while(!store.isEmpty()) {
            int index = store.pollFirst();
            areas[index] += (index-1)*heights[index];
        }

        int result = 0;
        for(int value : areas) {
            result = Math.max(result, value);
        }
        return result;
    }
}
