import java.util.Scanner;

public class LongestSubstringWithoutRepeatingCharacters {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println(lengthOfLongestSubstring(scanner.next()));
    }

    public static int lengthOfLongestSubstring(String s) {
        int[] characters = new int[256];
        int result = 0;
        for(int i = 0, j = 0; i < s.length(); i++) {
            j = (characters[s.charAt(i)] > 0) ? Math.max(j, characters[s.charAt(i)]) : j;
            characters[s.charAt(i)] = i+1;
            result = Math.max(result, i-j+1);
        }

        return result;
    }
}
