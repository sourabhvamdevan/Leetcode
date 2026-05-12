class Solution {
public:
    int min_operations(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return 0;

   
        vector<int> b(n);
        for(int i=0;i<n;i++){
            b[i]=nums[i]-i;
        }

    
        vector<int> dp(n, 1);
        int maxLNDS = 1;

        for(int i=1;i<n;i++)
        
        {
            for (int j = 0; j < i; j++) {
                if(b[i]>=b[j]){
                    
                    
                    dp[i]=max(dp[i], dp[j] + 1);
    }
            }
            maxLNDS=max(maxLNDS, dp[i]);
        }

        return n-maxLNDS;
    }
};