public class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        int len = 0, j = 0;
        for (int i = 0; i < nums.length; i++) {
            int k = j;
            while (nums[k] == nums[j]) {
                k++;
                if (k == nums.length) {
                    nums[i] = nums[j];
                    len++;
                    return len;
                }
            }
            nums[i] = nums[j];
            len++;
            j = k;
        }
        return len;
    }
}