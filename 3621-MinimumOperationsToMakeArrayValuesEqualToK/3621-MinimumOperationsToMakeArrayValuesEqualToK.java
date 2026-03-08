// Last updated: 08/03/2026, 13:23:42
class Solution {
    public int minOperations(int[] nums, int k) {
        Arrays.sort(nums);
        int min=nums[0];
        if(min<k) return -1;
        int cnt=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>k) cnt++;
            while(i+1<nums.length && nums[i]==nums[i+1]){
                i++;
            }
        }
        return cnt;
    }
}