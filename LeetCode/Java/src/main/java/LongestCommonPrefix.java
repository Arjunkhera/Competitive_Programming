public class LongestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) return "";
        if(strs.length == 1) return strs[0];

        String result = strs[0];
        int j = 0;
        for(int i = 1; i < strs.length; i++) {
            String compare = strs[i];
            j = 0;
            while(j < result.length() && j < compare.length() && result.charAt(j) == compare.charAt(j)) {
                j++;
            }
            if(j == 0) {
                return "";
            }
            result = result.substring(0,j);
        }
        return result;
    }
}
