// Last updated: 08/03/2026, 13:23:29


class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int n = nums.size();
        int minSum = Integer.MAX_VALUE;
        boolean found = false;

        
        for (int length = l; length <= r; length++) {
           
            for (int start = 0; start <= n - length; start++) {
                int sum = 0;
                for (int k = start; k < start + length; k++) {
                    sum += nums.get(k);
                }
                if (sum > 0) {
                    minSum = Math.min(minSum, sum);
                    found = true;
                }
            }
        }

   
        return found ? minSum : -1;
    }

  
    public static void main(String[] args) {
        Solution solution = new Solution();
        List<Integer> nums1 = Arrays.asList(3, -2, 1, 4);
        int l1 = 2;
        int r1 = 3;
        System.out.println(solution.minimumSumSubarray(nums1, l1, r1)); 

        List<Integer> nums2 = Arrays.asList(-2, 2, -3, 1);
        int l2 = 2;
        int r2 = 3;
        System.out.println(solution.minimumSumSubarray(nums2, l2, r2));  

        List<Integer> nums3 = Arrays.asList(1, 2, 3, 4);
        int l3 = 2;
        int r3 = 4;
        System.out.println(solution.minimumSumSubarray(nums3, l3, r3));  // Output: 3
    }
}
