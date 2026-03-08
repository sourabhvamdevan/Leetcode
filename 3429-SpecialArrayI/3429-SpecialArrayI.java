// Last updated: 08/03/2026, 13:24:19
class Solution {

    public boolean isArraySpecial(int[] nums) {
       
        for (int index = 0; index < nums.length - 1; index++) {
            
            if (nums[index] % 2 == nums[index + 1] % 2) {
                
                return false;
            }
        }

        
        return true;
    }
}
