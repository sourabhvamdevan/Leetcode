// Last updated: 08/03/2026, 13:23:16
class Solution {
    public int maxLength(int[] nums) {
        int n = nums.length;
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            int prod = 1;
            int gcd = 0;
            int lcm = 1;
            
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                gcd = (gcd == 0) ? nums[j] : gcd(gcd, nums[j]);
                lcm = lcm(lcm, nums[j]);

                if (prod == lcm * gcd) {
                    maxLength = Math.max(maxLength, j - i + 1);
                }
            }
        }

        return maxLength;
    }

    
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    
    private int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums1 = {1, 2, 1, 2, 1, 1, 1};
        System.out.println(sol.maxLength(nums1));  

        int[] nums2 = {2, 3, 4, 5, 6};
        System.out.println(sol.maxLength(nums2));  

        int[] nums3 = {1, 2, 3, 1, 4, 5, 1};
        System.out.println(sol.maxLength(nums3));  
    }
}
