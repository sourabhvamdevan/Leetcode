class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        bool buy=true;
        vector<int>dp(2,0);
        dp[0]=-prices[0];
        for(int i=1; i<n; i++){
            vector<int> curr(2,0);
            curr[0]=max(dp[0], dp[1]-prices[i]);
            curr[1]=max(dp[1],dp[0]+prices[i]-fee);
            dp=curr;

        }


        return dp[1];
    }
};