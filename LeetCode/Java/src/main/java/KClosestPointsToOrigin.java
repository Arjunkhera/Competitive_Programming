import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

public class KClosestPointsToOrigin {
    public static void main(String[] args) {
        int[] arr = new int[]{9,3,5,7,11,12};

        int mid = staticPartition(arr, 0, arr.length - 1);
    }

    public int[][] sorting(int[][] points, int K) {
        Arrays.sort(points, (p1, p2) -> p1[0]*p1[0] + p1[1]*p1[1] - p2[0]*p2[0] - p2[1]*p2[1]);
        return Arrays.copyOfRange(points, 0, K);
    }

    public int[][] heap(int[][] points, int K) {
        PriorityQueue<int[]> distances = new PriorityQueue<>((p1, p2) -> p2[0] * p2[0] + p2[1] * p2[1] - p1[0] * p1[0] - p1[1] * p1[1]);

        for(int[] p : points) {
            distances.offer(p);
            if(distances.size() > K) {
                distances.poll();
            }
        }

        return distances.toArray(new int[0][]);
    }

    public int[][] quickSort(int[][] point, int K) {
        int left = 0;
        int right = point.length - 1;
        while(left < right) {
            int mid = partition(point, left, right);
            if(mid == K) break;
            if(mid <   K) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return Arrays.copyOfRange(point, 0, K);
    }

    public int partition(int[][] arr, int left, int right) {
        int[] pivot = arr[left];
        while(left < right) {
            while(left < right && distance(arr[right], pivot) >= 0) right--;
            arr[left] = arr[right];
            while(left < right && distance(arr[left], pivot) <= 0) left++;
            arr[right] = arr[left];
        }
        arr[left] = pivot;
        return left;
    }

    public int distance(int[] p1, int[] p2) {
        return p1[0]*p1[0] + p1[1]*p1[1] - p2[0]*p2[0] - p2[1]*p2[1];
    }

    public static int staticPartition(int[] arr, int left, int right) {
        int pivot = arr[left];
        while(left < right) {
            while(left < right && arr[right] >= pivot) right--;
            arr[left] = arr[right];
            while(left < right && arr[left] <= pivot) left++;
            arr[right] = arr[left];
        }
        arr[left] = pivot;
        return left;
    }
}
