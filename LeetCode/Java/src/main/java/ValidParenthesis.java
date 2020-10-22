import java.util.ArrayDeque;
import java.util.Deque;

public class ValidParenthesis {
    public static boolean isValid(String s) {
        Deque<Character> store = new ArrayDeque<>();
        char character;
        for(int i = 0; i < s.length(); i++) {
            character = s.charAt(i);
            if(character == '(' || character == '{' || character == '[') {
                store.offerLast(character);
            } else {
                Character last = store.pollLast();
                if(last == null) return false;
                switch (character) {
                    case ')' :
                        if(last != '(') return false;
                        break;
                    case '}' :
                        if(last != '{') return false;
                        break;
                    case ']' :
                        if(last != '[') return false;
                        break;
                }
            }
        }
        return store.isEmpty();
    }

    public static void main(String[] args) {
        isValid("{[]}");
    }
}
