#define vvi vector<vector<int>>


class Solution {
public:
    int eggDrop(int n, int k) {
       
        
        vvi dp(k + 1, vector<int>(n + 1, 0));
        int moves = 0;

        while (dp[moves][n] < k) {
            moves++;
            for (int eggs = 1; eggs <= n; eggs++) {
               
                dp[moves][eggs] = dp[moves - 1][eggs - 1] + dp[moves - 1][eggs] + 1;
                
    }
        }

        return moves;
    }
};