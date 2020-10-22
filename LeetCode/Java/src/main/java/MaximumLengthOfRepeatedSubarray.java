public class MaximumLengthOfRepeatedSubarray {
    public int findLength(int[] A, int[] B) {
        if(A.length == 0 || B.length == 0) return 0;

        int result = 0;
        int[][] store = new int[2][A.length + 1];
        for(int i = 1; i <= B.length; i++) {
            for(int j = 1; j <= A.length; j++) {
                if(B[i-1] == A[j-1]) {
                    store[1][j] = store[0][j-1] + 1;
                    result = Math.max(result, store[1][j]);
                }
            }

            System.arraycopy(store[1], 0, store[0], 0, A.length + 1);
        }

        return result;
    }
}
