class Solution {
    int n,m;
    int dp[51][51];

    map<pair<pair<int, int>, int>, vector<string>> memo;

    vector<string> solve(string& s1, string& s2, int i, int j, int len) {
 
        if (len ==0) return {""};
        if (i >= n or j >= m) return {};


        if (memo.count({{i, j}, len}))return memo[{{i, j},len}];

        vector<string> res;


        for (char c = 'a'; c <= 'z'; c++)
        {
            bool found=false;

            for(int r=i;r<n;r++){
                if(s1[r]==c){
          
                    for (int c_idx = j; c_idx < m; c_idx++) {
                        if (s2[c_idx] == c) {
                        
                            if(dp[r][c_idx]==len){
                                vector<string> suffixes = solve(s1, s2, r + 1, c_idx + 1, len - 1);
                                for (const string& s : suffixes) {
                                    res.push_back(c + s);
                                }
                                
                                
                    found=true;
                                break;
                            }
                            
                            
                }
                    }
                }
                if (found) break;
            }
        }
        return memo[{{i, j}, len}] = res;
    }

public:
    vector<string> allLCS(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        memo.clear();


        for (int i = 0; i <= n; i++) dp[i][m] = 0;
        for (int j = 0; j <= m; j++) dp[n][j] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        int maxLen = dp[0][0];
        if (maxLen == 0) return {};

        return solve(s1, s2, 0, 0, maxLen);
    }
};