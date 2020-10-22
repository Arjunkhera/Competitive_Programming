public class ZigZagConversion {
    public String convert(String s, int numRows) {
        if(s.isEmpty() || s.length() == 1 || numRows == 1) return s;

        StringBuilder result = new StringBuilder();
        for(int i = 0; i < numRows; i++) {
            boolean direction = i != numRows - 1;
            int current = i;
            while(current < s.length()) {
                result.append(s.charAt(current));

                if(direction) {
                    current = current + 2*(numRows-i-1);
                    if(i != 0) {
                        direction = false;
                    }
                } else {
                    current = current + 2*i;
                    if(i != numRows-1) {
                        direction = true;
                    }
                }
            }
        }

        return result.toString();
    }
}
