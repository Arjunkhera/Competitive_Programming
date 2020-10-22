import java.util.HashMap;
import java.util.Map;

public class KDiffPairsInArray {
    public int findPairs(int[] nums, int k) {
        if(nums.length == 0) return 0;

        int result = 0;
        Map<Integer, Integer> store = new HashMap<>();
        for (int num : nums) {
            if (store.containsKey(num)) {
                if(k == 0 && store.get(num) == 0) {
                    result += 1;
                    store.put(num, 1);
                }
                continue;
            }

            if (store.containsKey(num - k)) {
                result += 1;
            }
            if (store.containsKey(num + k)) {
                result += 1;
            }
            store.put(num, 0);
        }

        return result;
    }
}
