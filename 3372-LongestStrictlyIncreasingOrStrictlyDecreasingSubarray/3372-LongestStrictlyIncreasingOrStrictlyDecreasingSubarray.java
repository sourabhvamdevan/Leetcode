// Last updated: 08/03/2026, 13:24:21


class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;
        int i = 0, ans = 0;
        int inc = 1, dec = 1;

        if (n == 1) return 1;

        for (i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                dec = 1;
            } else if (nums[i] < nums[i - 1]) {
                dec++;
                inc = 1;
            } else {
                inc = 1;
                dec = 1;
            }
            ans = Math.max(ans, Math.max(dec, inc));
        }

        return ans;
    }
}
