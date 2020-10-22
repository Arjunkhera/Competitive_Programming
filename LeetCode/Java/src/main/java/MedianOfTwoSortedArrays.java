public class MedianOfTwoSortedArrays {
    public static void main(String[] args) {

    }

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if(nums1.length > nums2.length) {
            int[] temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }

        int m = nums1.length;
        int n = nums2.length;
        int imin = 0;
        int imax = m;
        int mid = (m+n+1)/2;

        while(imin <= imax) {
            int i = (imax + imin)/2;
            int j = mid - i;

            if(i < m && nums1[i] < nums2[j-1]) {
                imin = i+1;
                continue;
            }
            if(i > 0 && nums2[j] < nums1[i-1]) {
                imax = i-1;
                continue;
            }

            double max_left;
            if(i == 0) max_left = nums2[j-1];
            else if(j == 0) max_left = nums1[i-1];
            else max_left = Math.max(nums1[i-1], nums2[j-1]);

            if((m+n) % 2 == 1) return max_left;

            double min_right;
            if(i == m) min_right = nums2[j];
            else if(j == n) min_right = nums1[i];
            else min_right = Math.min(nums1[i], nums2[j]);

            return ((double) max_left + (double)min_right)/2;
        }

        return 0;
    }
}
