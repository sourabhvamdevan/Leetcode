class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;

     
        if ((totalSum + target) % 2 != 0 || abs(target) > totalSum) {
            return 0;
        }

        int s1=(totalSum+target)/2;
        
    
        if (s1<0) return 0;

  
        vector<int> dp(s1 + 1, 0);
        dp[0] = 1; 

        for (int num : arr){
    
            for (int j = s1; j >= num; --j) {
                dp[j] += dp[j - num];
    }
        }

        return dp[s1];
    }
};