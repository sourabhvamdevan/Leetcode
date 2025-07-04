class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int[] dp=new int[n+1];
        dp[0]=10;
        int a=9;
        int curr=9;
        for(int i=1;i<n;i++){
            curr=curr*a;
            a--;
            dp[i]=curr+dp[i-1];
        }
        return dp[n-1];
    }
}