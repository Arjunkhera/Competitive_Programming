import java.util.*;

public class ThreeSum {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();

        Arrays.sort(nums);
        int current;
        int sum;
        for(int i = 0; i < nums.length-2; i++) {
            current = nums[i];
            int j = i+1;
            int k = nums.length - 1;
            while(j < k) {
                sum = current + nums[j] + nums[k];
                if(sum > 0) {
                    k--;
                    continue;
                } else if(sum < 0){
                    j++;
                    continue;
                }

                boolean isPresent = false;
                for(int l = 0; l < result.size(); l++) {
                    if (result.get(l).get(0) == current && result.get(l).get(1) == nums[j] && result.get(l).get(2) == nums[k]) {
                        isPresent = true;
                        break;
                    }
                }
                if(!isPresent) result.add(new ArrayList<>(Arrays.asList(current, nums[j], nums[k])));

                j++;
                k--;
            }
        }

        return result;
    }
}
