class Solution {
  public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) return 0;

        int k = costs[0].size();
        if (k == 0) return -1;
        

        if (k == 1) return (n == 1 ? costs[0][0] : -1);

        vector<int> dp = costs[0];

        for (int i = 1; i < n; i++) {
            int min1 = INT_MAX, min2 = INT_MAX, c1 = -1;

         
            for (int c = 0; c < k; c++) {
                if (dp[c] < min1) {
                    min2 = min1;
                    min1 = dp[c];
                    c1 = c;
                } else if (dp[c] < min2) {
                    min2 = dp[c];
                }
                
                
            }

            vector<int> newdp(k);

            for (int c = 0; c < k; c++) {
                if (c == c1)
                    newdp[c] = costs[i][c] + min2;
                else
                    newdp[c] = costs[i][c] + min1;
            }

            dp = newdp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
