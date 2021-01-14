import java.util.Arrays;
import java.util.List;

public class WordBreak {
    public boolean wordBreak(String s, List<String> wordDict) {
        int[] dp = new int[s.length()];
        return solve(s, wordDict, dp);
    }

    public boolean solve(String s, List<String> wordDict, int[] dp) {
        if(s.isEmpty()) return true;

        int currentIndex = dp.length - s.length();
        if(dp[currentIndex] == 2) {
            return true;
        } else if(dp[currentIndex] == 1) {
            return false;
        }

        for(String word : wordDict) {
            if(s.startsWith(word)) {
                if(solve(s.substring(word.length()), wordDict, dp)) {
                    dp[currentIndex] = 2;
                    return true;
                }
            }
        }

        dp[currentIndex] = 1;
        return false;
    }
}
