import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.stream.IntStream;

public class TwoSum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = 3;
        int target = 6;
        int[] numbers = IntStream.range(0, N).map(i -> scanner.nextInt()).toArray();
        System.out.println(Arrays.toString(twoSum(numbers, target)));
    }

    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> store = new HashMap<>();

        for(int i = 0; i < nums.length; i++) {
            int difference = target - nums[i];

            if(store.containsKey(difference)) {
                return new int[] {store.get(difference), i};
            }
            store.put(nums[i], i);
        }

        return null;
    }
}
