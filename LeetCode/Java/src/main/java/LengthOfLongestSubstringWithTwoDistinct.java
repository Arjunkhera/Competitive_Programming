import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class LengthOfLongestSubstringWithTwoDistinct {

    public int lengthOfLongestSubstringTwoDistinct(String s) {
        if(s.isEmpty()) return 0;

        int startIndex = 0;
        int endIndex = 0;
        int result = 0;
        Map<Character, Integer> store = new HashMap<>();

        while(endIndex < s.length()) {
            store.put(s.charAt(endIndex), endIndex + 1);

            if(store.size() == 3) {
                startIndex = Collections.min(store.values());
                store.remove(s.charAt(startIndex - 1));
            }

            result = Math.max(result, endIndex - startIndex + 1);
            endIndex += 1;
        }
        return result;
    }
}
