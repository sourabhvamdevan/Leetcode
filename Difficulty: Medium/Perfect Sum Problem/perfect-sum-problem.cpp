class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
    
        vector<int> dp(target + 1, 0);


        dp[0]=1;

        for(int i=0;i<n;i++){
          
            for (int j=target;j>=arr[i];j--){
                dp[j]=dp[j] + dp[j - arr[i]];
        }
            
            
        }

        return dp[target];
    }
};