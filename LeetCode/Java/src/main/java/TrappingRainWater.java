public class TrappingRainWater {
    public int trap(int[] height) {
        int area = 0;
        int curMax = -1;

        int[] left = new int[height.length];
        for(int i = 0; i < height.length; i++) {
            if(height[i] > curMax) {
                curMax = height[i];
            }
            left[i] = curMax;
        }

        curMax = -1;
        int[] right = new int[height.length];
        for(int i = height.length - 1; i >= 0; i--) {
            if(height[i] > curMax) {
                curMax = height[i];
            }
            right[i] = curMax;
        }


        for(int i = 0; i < height.length; i++) {
            if(height[i] == left[i] || height[i] == right[i]) continue;
            area += Math.min(left[i], right[i]) - height[i];
        }
        return area;
    }
}
