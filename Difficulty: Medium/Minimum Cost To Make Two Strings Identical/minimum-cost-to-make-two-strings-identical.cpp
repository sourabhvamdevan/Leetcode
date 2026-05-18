class Solution {
  public:
    int findMinCost(string x, string y, int costX, int costY) {
        int m = x.length();
        int n = y.length();
    
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
   
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (x[i - 1] == y[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        

        int lcs_length = dp[m][n];
        
 
        int deletions_x = m - lcs_length;
        int deletions_y = n - lcs_length;
        
   
        return (deletions_x * costX) + (deletions_y * costY);
    }
};