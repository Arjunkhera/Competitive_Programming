import java.util.ArrayList;
import java.util.List;

public class MaximumDistanceInArrays {
    public int maxDistance(List<List<Integer>> arrays) {
        long distance = 0;
        long temp;

        List<Integer> arr;
        arr = arrays.get(0);
        long maximum = arr.get(arr.size()-1);
        long minimum = arr.get(0);

        for(int i = 1;i < arrays.size(); i++) {
            arr = arrays.get(i);
            temp = Math.max(
                    Math.abs(arr.get(arr.size()-1) - minimum),
                    Math.abs(maximum - arr.get(0))
            );
            distance = Math.max(distance, temp);

            maximum = Math.max(arr.get(arr.size()-1), maximum);
            minimum = Math.min(arr.get(0), minimum);
        }

        return (int) distance;
    }
}
