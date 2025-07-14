

class Solution {
public:
    bool isPowerOfFive(string &s, int i, int j) {
        if (s[i] == '0' && j > i) return false;
        int num = 0;
        for (int k = i; k <= j; ++k) {
            num = num * 2 + (s[k] - '0');
            if (num > INT_MAX) return false;
        }
        
        
        
        if (num == 0) return false;
        while (num % 5 == 0) num /= 5;
        return num == 1;
        
        
    }

    int dfs(string &s, int i, vector<int> &dp) {
        if (i == s.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for (int j = i; j < s.size(); ++j) {
            if (isPowerOfFive(s, i, j)) {
                int res = dfs(s, j + 1, dp);
                if (res != INT_MAX)
                    ans = min(ans, 1 + res);
            }
            
            
            
        }
        
        
        return dp[i] = ans;
    }

    int cuts(string s) {
        vector<int> dp(s.size(), -1);
        int res = dfs(s, 0, dp);
        return res == INT_MAX ? -1 : res;
    }
};
