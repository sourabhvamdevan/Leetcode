class Solution {
public:
    int ways(int ind, vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(ind==0){
            if(amount%coins[ind] == 0){
                return 1;
            }
            return 0;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int take =0;
        int ntake = ways(ind-1,coins,amount,dp);
        if(coins[ind]<=amount){
            take = ways(ind,coins,amount-coins[ind],dp);
        }
        return dp[ind][amount] = take + ntake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return ways(n-1,coins,amount,dp);
        
    }
};