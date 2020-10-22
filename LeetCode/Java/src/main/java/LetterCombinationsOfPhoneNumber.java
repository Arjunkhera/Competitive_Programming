import java.util.*;

public class LetterCombinationsOfPhoneNumber {

    Map<Integer, String> keyMap = new HashMap<Integer, String>() {{
        put(2,"abc");
        put(3,"def");
        put(4,"ghi");
        put(5,"jkl");
        put(6,"mno");
        put(7,"pqrs");
        put(8,"tuv");
        put(9,"wxyz");
    }};

    List<String> result = new ArrayList<>();

    public void recursion(String digits, String output) {
        if(digits.isEmpty()) {
            result.add(output);
            return;
        }

        int digit = digits.charAt(0) - 48;
        if(digit == 1) {
            recursion(digits.substring(1), output);
            return;
        }

        String string = keyMap.get(digit);
        for(int i = 0; i < string.length(); i++) {
            recursion(digits.substring(1), output + string.charAt(i));
        }
    }

    public List<String> letterCombinations(String digits) {
        if(!digits.isEmpty()) recursion(digits, "");
        return result;
    }

    public static void main(String[] args) {
        // letterCombinations("23").forEach(System.out::println);
    }
}
