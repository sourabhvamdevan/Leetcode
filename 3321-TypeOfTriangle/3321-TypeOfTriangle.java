// Last updated: 08/03/2026, 13:24:29
class Solution {
    public String triangleType(int[] nums) {
        
        if (nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[1] + nums[2] <= nums[0]) {
            return "none";
        }
        
    
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        
        
        if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
            return "isosceles";
        }
        
        
        return "scalene";
    }
}
