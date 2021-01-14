public class MaximumConsecutiveOnes {
    public int longestOnes(int[] A, int K) {
        int numberOfOnes = 0;
        int startIndex = 0;
        int length = Integer.MIN_VALUE;

        for(int endIndex = 0; endIndex < A.length; endIndex++) {
            if(A[endIndex] == 1)
                numberOfOnes++;

            if(endIndex - startIndex + 1 - numberOfOnes > K) {
                if(A[startIndex] == 1)
                    numberOfOnes--;
                startIndex++;
            }


            length = Math.max(length, endIndex - startIndex +1);
        }

        return length;
    }
}
