class Solution {
    private:
    #define vb vector<bool>
public:
    bool canPartition(vector<int>& nums) {
       int n=nums.size();
       int sum=0;
       for(int i=0;i<n;i++)
        sum+=nums[i];
        if(sum %2!=0) return false;
        int target=sum/2;
vb dp(target+1,false);
dp[0]=true;
for(int i=1; i<n;i++){
    for(int j=target;j>=nums[i]; j--){
        dp[j]=dp[j] | dp[j-nums[i]];

    }
}

return dp[target];

    }

       
    
};