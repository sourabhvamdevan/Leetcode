// Last updated: 08/03/2026, 13:23:17
class Solution {
    public int countSubarrays(int[] nums) {
        int count=0;
        for(int i=1;i<nums.length-1;++i){
            if(nums[i]%2==0&& nums[i]/2==nums[i-1]+ nums[i + 1]){

                count++;

                
            }
        }



        return count;
    }
}