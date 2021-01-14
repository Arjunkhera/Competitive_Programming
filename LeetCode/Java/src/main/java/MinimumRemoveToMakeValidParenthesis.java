public class MinimumRemoveToMakeValidParenthesis {
    public String minRemoveToMakeValid(String s) {
        StringBuilder output = new StringBuilder();
        StringBuilder result = new StringBuilder();

        int open = 0;
        int extra = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == ')') {
                if (extra == 0) {
                    continue;
                }
                extra--;
            }

            if (ch == '(') {
                open++;
                extra++;
            }

            output.append(ch);
        }

        int openToAdd = open - extra;
        for (int i = 0; i < output.length(); i++) {
            char ch = output.charAt(i);
            if (ch == '(') {
                openToAdd--;
                if (openToAdd < 0) {
                    continue;
                }
            }

            result.append(ch);
        }

        return result.toString();
    }
}
