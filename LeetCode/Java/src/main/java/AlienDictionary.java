import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class AlienDictionary {
    Map<Character, List<Character>> graph = new HashMap<>();
    Map<Character, Boolean> seen = new HashMap<>();

    public String alienOrder(String[] words) {
        for(String word : words) {
            for(Character ch : word.toCharArray()) {
                graph.putIfAbsent(ch, new ArrayList<>());
            }
        }

        for(int i = 0; i < words.length - 1; i++) {
            String word1 = words[i];
            String word2 = words[i+1];

            if(word1.length() > word2.length() && word1.startsWith(word2)) {
                return "";
            }

            for(int j = 0; j < Math.min(word1.length(), word2.length()); j++) {
                if(word1.charAt(j) != word2.charAt(j)) {
                    graph.get(word2.charAt(j)).add(word1.charAt(j));
                    break;
                }
            }
        }

        StringBuilder output = new StringBuilder();
        for(Character node : graph.keySet()) {
            if(!dfs(node, output)) {
                return "";
            }
        }

        return output.toString();
    }

    public Boolean dfs(Character node, StringBuilder output) {
        if(seen.containsKey(node)) {
            return seen.get(node);
        }

        seen.put(node, false);
        for(Character neighbour : graph.get(node)) {
            if(!dfs(neighbour, output)) {
                return false;
            }
        }

        output.append(node);
        seen.put(node, true);
        return true;
    }
}
