public class LongestCommonSubsequence {
    public int longestCommonSubsequence(String text1, String text2) {
        if(text1.isEmpty() || text2.isEmpty()) return 0;

        int[][] store = new int[2][text1.length() + 1];
        for(int i = 1; i <= text2.length(); i++) {
            for(int j = 1; j <= text1.length(); j++) {
                  if(text2.charAt(i-1) == text1.charAt(j-1)) {
                      store[1][j] = store[0][j-1] + 1;
                  } else {
                      store[1][j] = Math.max(store[1][j-1], store[0][j]);
                  }
            }

            System.arraycopy(store[1], 0, store[0], 0, text1.length() + 1);
        }

        return store[1][text1.length()];
    }
}
