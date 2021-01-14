public class ConsecutiveCharacters {
    public int maxPower(String s) {
        int result = 0;

        int current = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s.charAt(i) == s.charAt(i-1)) {
                current++;
                continue;
            }

            result = Math.max(result, current);
            current = 1;
        }
        result = Math.max(result, current);

        return result;
    }
}
