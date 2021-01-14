import java.util.*;

public class FindMinimumHeightTrees {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if(n == 1) return new ArrayList<>(List.of(0));
        if(n == 2) return new ArrayList<>(List.of(edges[0][0], edges[0][1]));

        int minHeight = Integer.MAX_VALUE;
        List<Integer> results = new ArrayList<>();
        Map<Integer, Set<Integer>> graph = new HashMap<>();

        for (int[] arr : edges) {
            if (graph.containsKey(arr[0])) {
                Set<Integer> edge = graph.get(arr[0]);
                edge.add(arr[1]);
            } else {
                Set<Integer> edge = new HashSet<>();
                edge.add(arr[1]);
                graph.put(arr[0], edge);
            }
        }

        for(Map.Entry<Integer, Set<Integer>> node : graph.entrySet()) {
            // Ignore leaf nodes
            if(node.getValue().size() == 1) continue;

            Queue<Integer> bfs = new ArrayDeque<>();
            Queue<Integer> heights = new ArrayDeque<>();

            bfs.add(node.getKey());
            heights.add(0);
            while(!bfs.isEmpty()) {
                Integer currentNode = bfs.poll();
                Integer currentHeight = heights.poll() + 1;
                if(currentHeight > minHeight) break;
                for(Integer nodeEdge : graph.get(currentNode)) {
                    if(graph.get(nodeEdge).size() == 1) {
                        if(currentHeight < minHeight) {
                            results.clear();
                            results.add(node.getKey());
                            minHeight = currentHeight;
                        } else if(currentHeight == minHeight) {
                            results.add(node.getKey());
                        }

                        bfs.clear();
                        break;
                    }

                    graph.get(nodeEdge).forEach(vertex -> {
                        bfs.offer(vertex);
                        heights.offer(currentHeight);
                    });
                }
            }

        }

        return results;
    }
}
