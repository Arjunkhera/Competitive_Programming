public class PalindromeNumber {
    public boolean isPalindrome(int x) {
        if(x < 0) return false;

        int reversedNumber = 0;
        int originalNumber = x;
        while(x != 0) {
            reversedNumber = reversedNumber*10 + x%10;
            x/=10;
        }

        return reversedNumber == originalNumber;
    }
}
