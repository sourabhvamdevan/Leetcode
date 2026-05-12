
class Solution {
  public:
    string longestSubstring(string& s) {
        int n=s.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        int max_len=0;
        int end_idx=0;
        
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
             
                if (s[i - 1] == s[j - 1] and dp[i - 1][j - 1] < (j - i)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    
                    if (dp[i][j]>max_len)
                    
                    
                    {
                        max_len = dp[i][j];
                        end_idx = i; 
                    }
                } else
                
                {
                    dp[i][j]=0;
                }
                
                
                
                
            }
        }
        
        if (max_len==0) return "-1";
        
     
        return s.substr(end_idx - max_len, max_len);
    }
};