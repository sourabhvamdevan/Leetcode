// Last updated: 08/03/2026, 13:23:12
class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int res=Math.abs(nums[0]-nums[nums.length-1]);

        for(int i= 1; i<nums.length; ++i)
        res=Math.max(res,Math.abs(nums[i]-nums[i-1]));
        return res;
    }
}