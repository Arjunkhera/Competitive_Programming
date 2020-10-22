public class RemoveDuplicatesFromSortedArray {
    public int removeDuplicates(int[] nums) {
        if(nums == null) return 0;

        int i = 0;
        int j = 0;
        while(i < nums.length) {

            while(j < nums.length && nums[i] == nums[j]) {
                j++;
            }

            if(j == nums.length) {
                break;
            }

            i++;
            nums[i] = nums[j];
        }

        return i+1;
    }
}
