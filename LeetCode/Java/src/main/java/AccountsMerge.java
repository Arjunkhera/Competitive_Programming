import java.util.*;
import java.util.stream.Collectors;

public class AccountsMerge {
    Map<String, List<String>> graph = new HashMap<>();
    Map<String, String> store = new HashMap<>();

    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        List<List<String>> result = new ArrayList<>();

        for(List<String> account : accounts) {
            String name = account.get(0);
            for(int i = 1; i < account.size(); i++) {
                String email = account.get(i);

                graph.computeIfAbsent(email, x -> new ArrayList<String>()).add(account.get(1));
                graph.computeIfAbsent(account.get(1), x -> new ArrayList<String>()).add(email);
                store.put(email, name);
            }
        }


        Set<String> visited = new HashSet<>();
        for(String node : graph.keySet()) {
            if(visited.contains(node)) {
                continue;
            }

            List<String> connected = new ArrayList<>();
            dfs(node, visited, connected);
            Collections.sort(connected);

            List<String> row = new ArrayList<>();
            row.add(store.get(node));
            row.addAll(connected);
            result.add(row);
        }

        visited.
        return result;
    }

    public void dfs(String node, Set<String> visited, List<String> connected) {
        if(visited.contains(node)) {
            return;
        }

        visited.add(node);
        connected.add(node);
        for(String neighbour : graph.get(node)) {
            dfs(neighbour, visited, connected);
        }
    }
}
