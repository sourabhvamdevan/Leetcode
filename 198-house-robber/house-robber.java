class Solution {
    public int rob(int[] nums) {
        int n=nums.length;
        if(n==0) return 0;
        if(n==1) return nums[0];
        int [] dp=new int[n+1];
        dp[0]=nums[0]; //no house no money
        dp[1]=Math.max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int incl=nums[i]+dp[i-2];
            int excl=dp[i-1];
            dp[i]=Math.max(incl,excl);
        }
        return dp[n-1];
    }
}