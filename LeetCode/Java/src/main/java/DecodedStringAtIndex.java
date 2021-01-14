public class DecodedStringAtIndex {
    public String decodeAtIndex(String s, int K) {
        long length = 0;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            if(Character.isDigit(s.charAt(i))) {
                length *=  Character.getNumericValue(s.charAt(i));
            } else {
                length++;
            }
        }


        for(int i = n-1; i >= 0; i--) {
            char current = s.charAt(i);
            K %= length;
            if(K == 0 && Character.isLetter(current)) {
                return Character.toString(current);
            }

            if(Character.isDigit(current)) {
                length /= Character.getNumericValue(current);
            } else {
                length--;
            }
        }

        return "";
    }
}
