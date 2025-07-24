class Solution {
    private:
    #define pb push_back
    #define vi vector<int>

public:
    int maxCoins(vector<int>& nums) {
        nums.pb(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(nums.size(),vi(nums.size()));
        for(int i=nums.size()-2;i>=1;i--){
            for(int j=i;j<nums.size()-1;j++){
                int ans=INT_MIN;
                for(int k=i;k<=j;k++){
                    ans=max(ans,(nums[i-1]*nums[j+1]*nums[k])+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=ans;
            
            }
        }
        return dp[1][nums.size()-2];
    }
};