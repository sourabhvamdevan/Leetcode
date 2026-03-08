// Last updated: 08/03/2026, 13:23:56
class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        for (int i = 0; i < k; i++) {
            int minIndex = findMinIndex(nums);
            nums[minIndex] *= multiplier;
        }
        return nums;
    }

    private int findMinIndex(int[] nums) {
        int minIndex = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
        }
        return minIndex;
    }

    
    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] nums1 = {2, 1, 3, 5, 6};
        int k1 = 5;
        int multiplier1 = 2;
        int[] result1 = solution.getFinalState(nums1, k1, multiplier1);
        System.out.println(Arrays.toString(result1));  

        int[] nums2 = {1, 2};
        int k2 = 3;
        int multiplier2 = 4;
        int[] result2 = solution.getFinalState(nums2, k2, multiplier2);
        System.out.println(Arrays.toString(result2));  
    }
}
