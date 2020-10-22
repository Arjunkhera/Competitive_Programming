import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class MeetingRoomsTwo {
    public int minMeetingRooms(int[][] intervals) {
        if(intervals.length == 0) return 0;

        PriorityQueue<Integer> rooms = new PriorityQueue<Integer>(intervals.length);
        rooms.add(intervals[0][1]);
        Arrays.sort(intervals, Comparator.comparingInt((int[] arr) -> arr[0]));

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= rooms.peek()) {
                rooms.poll();
            }

            rooms.add(intervals[i][1]);
        }

        return rooms.size();
    }
}
