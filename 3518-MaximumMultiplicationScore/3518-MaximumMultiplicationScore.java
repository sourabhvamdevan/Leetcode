// Last updated: 08/03/2026, 13:24:01
class Solution {
    public long maxScore(int[] a, int[] b) {
        int n = b.length;

       
        long[][] dp = new long[5][n+1];

       
        for (int len = 1; len <= 4; len++) {
            long maxPrev = Long.MIN_VALUE;
            for (int j = len; j <= n; j++) {
                maxPrev = Math.max(maxPrev, dp[len-1][j-1]);
                dp[len][j] = maxPrev + (long)a[len-1] * (long)b[j-1];
            }
        }

       
        long maxScore = Long.MIN_VALUE;
        for (int j = 4; j <= n; j++) {
            maxScore = Math.max(maxScore, dp[4][j]);
        }

        return maxScore;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        
        int[] a1 = {3, 2, 5, 6};
        int[] b1 = {2, -6, 4, -5, -3, 2, -7};
        System.out.println(solution.maxScore(a1, b1));  

        
        int[] a2 = {-1, 4, 5, -2};
        int[] b2 = {-5, -1, -3, -2, -4};
        System.out.println(solution.maxScore(a2, b2));  
    }
}
