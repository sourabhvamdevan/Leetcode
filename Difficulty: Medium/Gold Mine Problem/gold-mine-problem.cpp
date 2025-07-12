
class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size();       
        int m = mat[0].size();     
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
       
        for (int i = 0; i < n; i++)
            dp[i][m-1] = mat[i][m-1];
        
      
        for (int col = m - 2; col >= 0; col--) {
            for (int row = 0; row < n; row++) {
                int right = dp[row][col + 1];
                int right_up = (row > 0) ? dp[row - 1][col + 1] : 0;
                int right_down = (row < n - 1) ? dp[row + 1][col + 1] : 0;
                
                dp[row][col] = mat[row][col] + max({right, right_up, right_down});
            }
        }
        
     
        int maxGold = 0;
        for (int i = 0; i < n; i++)
            maxGold = max(maxGold, dp[i][0]);
        
        return maxGold;
    }
};
