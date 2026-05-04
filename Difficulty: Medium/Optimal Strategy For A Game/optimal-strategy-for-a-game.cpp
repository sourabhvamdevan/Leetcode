class Solution {
  public:
    long long maximumAmount(vector<int> &arr) {
        int n=arr.size();
     
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

     
        for(int gap=0;gap<n;gap++){
            for (int i = 0, j = gap; j < n; i++, j++) {
                
              
                if(gap==0){
                    dp[i][j]=arr[i];
                } else if (gap == 1)
                
                {
                    dp[i][j] = max(arr[i], arr[j]);
                } else {
               
                    long long pick_i = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                    long long pick_j = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                    
                    dp[i][j] = max(pick_i, pick_j);
                }
                
                
            }
            
            
            
            
        }

        return dp[0][n - 1];
    }
};