// Last updated: 08/03/2026, 13:24:27


class Solution {
    public boolean isPossibleToSplit(int[] nums) {
        int n = nums.length;
        if (n % 2 != 0) return false;

        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int num : nums) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        int distinctCount = 0;
        for (int count : freqMap.values()) {
            if (count > 2) return false;
            if (count == 2) distinctCount++;
        }

        return distinctCount <= n / 2;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums1 = {1, 1, 2, 2, 3, 4};
        System.out.println(sol.isPossibleToSplit(nums1)); 

        int[] nums2 = {1, 1, 1, 1};
        System.out.println(sol.isPossibleToSplit(nums2)); 
    }
}
