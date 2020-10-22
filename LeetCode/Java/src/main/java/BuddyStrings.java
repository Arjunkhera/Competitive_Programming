import java.util.HashSet;
import java.util.Set;

public class BuddyStrings {
    public boolean buddyStrings(String A, String B) {
        if(A.isEmpty() || B.isEmpty()) return false;
        if(A.length() != B.length()) return false;

        int[] mismatched = new int[2];
        int j = 0;
        for(int i = 0; i < A.length(); i++) {
            if(A.charAt(i) != B.charAt(i)) {
                if(j > 1) return false;
                mismatched[j] = i;
                j++;
            }
        }

        if(j == 1) return false;
        if(j == 0) {
            int[] duplicates = new int[26];
            boolean flag = false;
            for(int i = 0; i < A.length(); i++) {
                int index = A.charAt(i) - 97;
                duplicates[index] += 1;

                if(duplicates[index] > 1) {
                    flag = true;
                    break;
                }
            }
            return flag;
       }
        return A.charAt(mismatched[0]) == B.charAt(mismatched[1]) && A.charAt(mismatched[1]) == B.charAt(mismatched[0]);
    }
}
