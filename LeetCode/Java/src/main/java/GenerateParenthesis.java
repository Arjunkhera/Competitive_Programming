import java.util.ArrayList;
import java.util.List;

public class GenerateParenthesis {
    public void recursion(List<String> result, String output, int openingBrackets, int closingBrackets) {
        if(openingBrackets == 0 && closingBrackets == 0) {
            result.add(output);
            return;
        }

        if(openingBrackets > 0) recursion(result, output + "(", openingBrackets-1, closingBrackets+1);
        if(closingBrackets > 0) recursion(result, output + ")", openingBrackets, closingBrackets-1);
    }

    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        recursion(result, "", n, 0);

        return result;
    }
}
