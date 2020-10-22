import java.util.Arrays;
import java.util.Comparator;

public class MeetingRooms {
    public boolean canAttendMeetings(int[][] intervals) {
        if(intervals.length == 0 || intervals.length == 1) return true;

        Arrays.sort(intervals, Comparator.comparingInt((int[] ints) -> ints[0]));
        boolean canAttend = true;
        for(int i = 1; i < intervals.length; i++) {
            if(intervals[i][0] < intervals[i-1][1]) {
                canAttend = false;
                break;
            }
        }

        return canAttend;
    }
}
