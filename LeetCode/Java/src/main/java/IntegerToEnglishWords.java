import java.util.ArrayList;
import java.util.List;

public class IntegerToEnglishWords {
    public String numberToWords(int num) {
        if(num == 0) return "Zero";

        List<String> ones = new ArrayList<>(List.of(
                "",
                "One",
                "Two",
                "Three",
                "Four",
                "Five",
                "Six",
                "Seven",
                "Eight",
                "Nine"
        ));

        List<String> teens = new ArrayList<>(List.of(
                "Ten",
                "Eleven",
                "Twelve",
                "Thirteen",
                "Fourteen",
                "Fifteen",
                "Sixteen",
                "Seventeen",
                "Eighteen",
                "Nineteen"
        ));

        List<String> hundreds = new ArrayList<>(List.of(
                "Ten",
                "Twenty",
                "Thirty",
                "Forty",
                "Fifty",
                "Sixty",
                "Seventy",
                "Eighty",
                "Ninety"
        ));

        List<String> positions = new ArrayList<>(List.of(
                "",
                "Thousand",
                "Million",
                "Billion"
        ));

        String result = "";

        List<Integer> digits = new ArrayList<>();
        while(num != 0) {
            digits.add(num%10);
            num /= 10;
        }
        int length = digits.size();
        int i = 0;

        while(i < length) {
            String current = "";

            int first = digits.get(i);
            current = ones.get(first);

            i++;
            if(i < length) {
                int second = digits.get(i);

                if(second != 0) {
                    if(second == 1) {
                        current = teens.get(first);
                    } else {
                        if(current == "") {
                            current = hundreds.get(second - 1);
                        } else {
                            current = hundreds.get(second - 1) + " " + current;
                        }
                    }
                }
            }

            if(i/3 != 0 && !current.equals("")) {
                current = current + " " + positions.get(i/3);
            }

            i++;
            if(i < length) {
                int third = digits.get(i);

                if(third != 0) {
                    if(current.equals("")) {
                        if(i/3 != 0) {
                            current = ones.get(third) + " Hundred " + positions.get(i/3);
                        } else {
                            current = ones.get(third) + " Hundred";
                        }
                    } else {
                        current = ones.get(third) + " Hundred " + current;
                    }

                }
            }

            if(result.equals("")) {
                result = current;
            } else {
                if(current != "") result = current + " " + result;
            }
            i++;
        }

        return result;

    }
}
