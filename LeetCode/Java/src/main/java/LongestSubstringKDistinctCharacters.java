import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class LongestSubstringKDistinctCharacters {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        if(s.isEmpty() || k <= 0) return 0;

        int answer = Integer.MIN_VALUE;
        Map<Character, Integer> distinct = new HashMap<>();
        int startIndex = 0;
        for(int endIndex = 0; endIndex < s.length(); endIndex++) {
            distinct.put(s.charAt(endIndex), endIndex);

            if(distinct.size() > k) {
                int leftMostIndex = Collections.min(distinct.values());
                distinct.remove(s.charAt(leftMostIndex));
                startIndex = leftMostIndex + 1;
            }

            answer = Math.max(answer, endIndex - startIndex + 1);
        }

        return answer;
    }
}
