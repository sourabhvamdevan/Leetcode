class Solution {
  public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
   
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {

    
        if (i >= x && dp[i - x] != -1)
        {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }

 
        if (i >= y && dp[i - y] != -1) {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i >= z && dp[i - z] != -1) {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }

   
        if (dp[i] == 0) {
            dp[i] = -1;
        }
    }


    if (dp[n] == -1) {
        return 0;
    }


    return dp[n];
    }
};