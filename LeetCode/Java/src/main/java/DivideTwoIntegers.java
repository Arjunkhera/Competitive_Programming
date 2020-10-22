public class DivideTwoIntegers {
    public int divide(int dividend, int divisor) {
        if(divisor == 0 || dividend == 0) return 0;
        if(divisor == 1) {
            return dividend;
        } else if(divisor == -1) {
            if(dividend == Integer.MIN_VALUE) return Integer.MAX_VALUE;
            return -dividend;
        }

        int quotient = 0;
        if(dividend > 0 && divisor > 0) {
            while(dividend >= divisor) {
                quotient += 1;
                dividend -= divisor;
            }
        } else if(dividend < 0 && divisor < 0) {
            while(dividend <= divisor) {
                quotient += 1;
                dividend -= divisor;
            }
        } else if(dividend > 0 && divisor < 0) {
            while(-dividend >= divisor) {
                quotient -= 1;
                dividend += divisor;
            }
        } else {
            while(dividend >= -divisor) {
                quotient -= 1;
                dividend += divisor;
            }
        }

        return quotient;
    }
}
