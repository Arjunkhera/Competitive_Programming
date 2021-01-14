import java.util.HashMap;
import java.util.Map;

public class VerifyingAlienDictionary {
    public boolean isAlienSorted(String[] words, String order) {
        Map<Character, Integer> store = new HashMap<>();
        for(int i = 0; i < order.length(); i++) {
            store.put(order.charAt(i), i);
        }


        for(int i = 1; i < words.length; i++){
            int first = words[i-1].length();
            int second = words[i].length();

            int j = 0, k = 0;
            while(j < first && k < second) {
                Integer previous = store.get(words[i-1].charAt(j));
                Integer current = store.get(words[i].charAt(k));

                if(previous < current) break;
                if(previous > current) return false;

                j++;
                k++;
            }

            if(j < first && k == second) return false;
        }

        return true;
    }
}
