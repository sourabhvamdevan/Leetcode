
class Solution {
public:
    int r(int i,int j,vector<vector<int>>&dp,vector<int>cuts){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            ans=min(ans, cuts[j+1]-cuts[i-1]+ r(i,k-1,dp,cuts) + r(k+1,j,dp,cuts) );
        }
        dp[i][j]=ans;
        return ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size()));
        for(int i=cuts.size()-2;i>=1;i--){
            for(int j=1;j<=cuts.size()-2;j++){
                if(i>j)continue;
                int ans=INT_MAX;
                for(int k=i;k<=j;k++){
                    ans=min(ans,cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=ans;
            }
        }
        
        return dp[1][cuts.size()-2];
    }
};