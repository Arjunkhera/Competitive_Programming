public class MaximalSquare {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length;
        int columns = matrix[0].length;

        if (rows == 0 || columns == 0) {
            return 0;
        }

        int area = 0;
        int[] dp = new int[columns + 1];
        for (int i = 1; i <= rows; i++) {
            int prev = 0;
            for (int j = 1; j <= columns; j++) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = Math.min(Math.min(dp[j - 1], dp[j]), prev) + 1;
                } else {
                    dp[j] = 0;
                }

                area = Math.max(area, dp[j] * dp[j]);
                prev = temp;
            }
        }

        return area;
    }
}
