public class StringToInteger {
    public int myAtoi(String str) {
        long result = 0;
        boolean foundDigit = false;
        boolean isNegative = false;

        int i = 0;
        while(i < str.length() && str.charAt(i) == ' ') {
            i++;
        }
        if(i == str.length()) {
            return 0;
        }
        if(str.charAt(i) == '-') {
            isNegative = true;
            i++;
        } else if (str.charAt(i) == '+') {
            i++;
        }

        for(; i < str.length(); i++) {
            if(str.charAt(i) >= '0' && str.charAt(i) <= '9') {
                foundDigit = true;
                result = result*10 + (str.charAt(i)-'0');
            } else if (!foundDigit) {
                return 0;
            } else {
                break;
            }

            if(result > Integer.MAX_VALUE) {
                if(isNegative) {
                    return Integer.MIN_VALUE;
                }
                return Integer.MAX_VALUE;
            }
        }

        if(isNegative) result = -result;
        return (int) result;
    }
}
