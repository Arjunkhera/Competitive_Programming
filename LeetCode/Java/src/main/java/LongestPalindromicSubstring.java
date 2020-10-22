public class LongestPalindromicSubstring {

    public String checkPalindrome(String s, int first, int last) {
        while(first >=0 && last < s.length() && s.charAt(first) == s.charAt(last)) {
            first--;
            last++;
        }
        return s.substring(first+1, last);
    }

    public String longestPalindrome(String s) {
        if(s.isEmpty()) return "";
        if(s.length() == 1) return s;

        String result = "";
        for(int i = 0; i < s.length() - 1;i++) {
            String oddPalindrome = checkPalindrome(s,i,i);
            result = oddPalindrome.length() > result.length() ? oddPalindrome : result;

            String evenPalindrome = checkPalindrome(s,i,i+1);
            result = evenPalindrome.length() > result.length() ? evenPalindrome : result;
        }

        return result;
    }
}
