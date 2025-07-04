class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n=triangle.size();
        int [][] dp=new int[n+1][n+1];
        for(int i=n-1;i>=0;i--){  //traversing through levels
            for(int j=0;j<=i;j++){
                dp[i][j]=triangle.get(i).get(j)+Math.min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
}