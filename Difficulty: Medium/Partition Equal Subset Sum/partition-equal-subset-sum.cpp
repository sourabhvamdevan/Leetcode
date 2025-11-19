class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum % 2) return false;
        int target= sum /2;
        vector<bool> dp(target+1, false);
        dp[0]=true;
        for(int num:arr)
         for(int j=target; j>=num; --j)
         dp[j]= dp[j]|| dp[j-num];
         
         return dp[target];
    }
};