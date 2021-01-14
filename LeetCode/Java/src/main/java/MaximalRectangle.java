import java.util.ArrayDeque;
import java.util.Deque;

public class MaximalRectangle {
    public static class pair {
        int length;
        int breadth;
        int area;

        public pair(){
            this.length = 0;
            this.breadth = 0;
        }

        public pair(int length, int breadth) {
            this.length = length;
            this.breadth = breadth;
            this.area = this.length*this.breadth;
        }

        public void calculateArea() {
            this.area = this.length*this.breadth;
        }
    }

    public static int maximalRectangle(char[][] matrix) {
        int rows = matrix.length;
        int columns = matrix[0].length;
        if(rows == 0 || columns == 0) return 0;

        int area = 0;
        pair[][] dp = new pair[rows+1][columns+1];
        for(int i = 0; i <= rows; i++) {
            for (int j = 0; j <= columns; j++) {
                dp[i][j] = new pair();
            }
        }

        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= columns; j++) {
                if(matrix[i-1][j-1] == '1') {
                    dp[i][j].length = Math.min(dp[i][j-1].length, dp[i-1][j-1].length);
                    dp[i][j].breadth = Math.min(dp[i-1][j].breadth, dp[i-1][j-1].breadth);
                    dp[i][j].calculateArea();

                    area = Math.max(area, dp[i][j].area);
                }
            }
        }

        return area;
    }

    public static void main(String[] args) {
        char[][] matrix = new char[2][2];
        matrix[0][0] = '1';
        matrix[0][1] = '0';
        matrix[1][0] = '1';
        matrix[1][1] = '0';
        maximalRectangle(matrix);
    }
}
