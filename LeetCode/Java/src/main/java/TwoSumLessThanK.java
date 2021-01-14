import java.util.Arrays;

public class TwoSumLessThanK {
    public int twoSumLessThanK(int[] A, int K) {
        Arrays.sort(A);

        int left = 0;
        int right = A.length - 1;
        int result = -1;
        while(left < right) {
            if(A[left] + A[right] < K) {
                result = Math.max(result, A[left] + A[right]);
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
}
