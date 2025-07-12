class Solution {
public:
    int lengthOfLIS(vector<int>& sv) {
        int n=sv.size();
        vector<int>dp(n,1);
        for(int i=n-1;i>=0; i--){
            for(int j=i+1;j<n;j++){
                if(sv[j]>sv[i]){
                    dp[i]=max(dp[i],dp[j]+1);

                }
            }
        }


        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);

        }


        return ans;
     


    }
};