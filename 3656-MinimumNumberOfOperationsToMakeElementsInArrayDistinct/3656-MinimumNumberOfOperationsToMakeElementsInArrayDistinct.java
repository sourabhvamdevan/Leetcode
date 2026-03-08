// Last updated: 08/03/2026, 13:23:24
class Solution {
    public int minimumOperations(int[] nums) {
        for (int i = 0; i <= nums.length; i += 3) {
            Set<Integer> set = new HashSet<>();
            boolean hasDuplicate = false;
            for (int j = i; j < nums.length; j++) {
                if (!set.add(nums[j])) {
                    hasDuplicate = true;
                    break;
                }
            }
            if (!hasDuplicate) return i / 3;
        }
        return (nums.length + 2) / 3; // maximum operations needed
    }
}