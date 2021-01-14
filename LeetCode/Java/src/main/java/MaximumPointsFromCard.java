public class MaximumPointsFromCard {
    public int maxScore(int[] cardPoints, int k) {
        int result = 0;
        int currentSum = 0;
        int left = 0;
        while(left < k) {
            currentSum += cardPoints[left++];
        }
        left--;
        result = currentSum;

        int right = cardPoints.length - 1;
        while(right >= cardPoints.length - k) {
            currentSum -= cardPoints[left--];
            currentSum += cardPoints[right--];

            result = Math.max(result, currentSum);
        }

        return result;
    }

}
