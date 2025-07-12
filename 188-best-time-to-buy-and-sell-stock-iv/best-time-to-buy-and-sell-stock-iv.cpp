class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n==0||k==0)return 0;
        vector<vector<int>> dp(k+1,vector<int>(n,0));
        
        for(int t=1;t<=k;++t){
            int maxi=-prices[0];
            for(int d=1;d<n; ++d){
                dp[t][d]=max(dp[t][d-1], maxi +prices[d]);
                maxi=max(maxi,dp[t-1][d]-prices[d]);

            }
        }


        return dp[k][n-1];

        
    }
};