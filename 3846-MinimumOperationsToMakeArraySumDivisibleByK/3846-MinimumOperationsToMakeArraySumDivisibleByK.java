// Last updated: 08/03/2026, 13:22:50
class Solution {
    public int minOperations(int[] nums, int k) {
        int sum=0;
        for(int num:nums){
            sum+=num;

            
        }

        return sum%k;
    }
}