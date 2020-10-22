public class ContainerWithMostWater {
    public int maxArea(int[] height) {
        int maxArea = 0;
        int left = 0;
        int right = height.length-1;

        while(left < right) {
            maxArea = Math.max(maxArea, Math.min(height[left], height[right])*(right-left));
            if(height[left] < height[right]) {
                left+=1;
            } else {
                right-=1;
            }
        }

        return maxArea;
    }
}
