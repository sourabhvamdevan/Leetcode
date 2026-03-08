// Last updated: 08/03/2026, 13:24:09
class Solution{
    public int minOperations(int[] nums){
        int n = nums.length;
        int operations = 0;
        
        
        for (int i = 0; i <= n - 3; i++){
            if (nums[i] ==0) {
                
                nums[i] ^= 1;
                nums[i+1] ^= 1;
                nums[i+2] ^= 1;
                operations++;
            }
        }
        
        
        if(nums[n-2] == 0 || nums[n-1] == 0){
            return -1;
        }
        
        return operations;
    }
}