public class RegularExpressionMatching {
    public boolean isMatch(String s, String p) {
        if(p.isEmpty() && s.isEmpty()) return true;
        if(p.isEmpty()) return false;

        int[][] store = new int[p.length() + 1][s.length() + 1];
        store[0][0] = 1;

        for(int i = 1; i <= p.length(); i++) {
            for(int j = 0; j <= s.length(); j++) {
                char current = p.charAt(i-1);

                if(current == '*') {
                    if(i == 1) return false;
                    if(j == 0) {
                        store[i][0] = store[i-2][0];
                        continue;
                    }

                    char previous = p.charAt(i-2);
                    if(previous == '.') {
                        store[i][j] = store[i][j-1] + store[i-2][j];
                    } else if(previous >= 'a' && previous <= 'z') {
                        if(previous == s.charAt(j-1)) {
                            store[i][j] = store[i][j-1] + store[i-2][j];
                        } else {
                            store[i][j] = store[i-2][j];
                        }
                    }
                    continue;
                }

                if(j == 0) continue;
                if(current == '.') {
                    store[i][j] = store[i-1][j-1];
                    continue;
                }
                if(current >= 'a' && current <= 'z') {
                    if(current == s.charAt(j-1)) {
                        store[i][j] = store[i-1][j-1];
                    }
                    continue;
                }
                return false;
            }
        }

        return store[p.length()][s.length()] > 0;
    }
}
