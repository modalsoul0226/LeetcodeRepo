public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double median1 = findMedian(nums1);
        double median2 = findMedian(nums2);
        if (median1 == 0 || median2 == 0) return (median1 + median2);
        return (median1 + median2) / 2;
    }
    
    public double findMedian(int[] nums) {
        int len = nums.length;
        if (len == 0) return 0;
        else if (len == 1) return nums[0];
        else {
            int i = 0, j = 0;
            while (j < len - 1) {
                i++;
                j+=2;
            }
            if (j == len - 1) return (double)nums[i];
            else return (nums[i - 1] + nums[i]) / 2f;
        }
    }
}