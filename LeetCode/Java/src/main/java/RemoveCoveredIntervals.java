import java.util.Arrays;
import java.util.Comparator;

public class RemoveCoveredIntervals {
    public int removeCoveredIntervals(int[][] intervals) {
        Comparator<int[]> compare = (first, second) -> first[0] == second[0] ? second[1] - first[1] : first[0] - second[0];

        int result = 0;
        int current, previous = 0;
        Arrays.sort(intervals, compare);
        for(int[] interval : intervals) {
            current = interval[1];
            if(current > previous) {
                result+=1;
                previous = current;
            }
        }

        return result;
    }
}
