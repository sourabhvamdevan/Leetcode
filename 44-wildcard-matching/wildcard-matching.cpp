class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[m][n] = true; 

        
        for(int i=m-1;i>=0;--i){

            if (p[i] == '*') dp[i][n] = dp[i + 1][n];
            else break;
        }

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (p[i] == s[j] || p[i] == '?') {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else if (p[i] == '*') {
                    dp[i][j] = dp[i + 1][j]   
                             || dp[i][j + 1]; 
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[0][0];
    }
};