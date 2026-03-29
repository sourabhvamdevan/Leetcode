class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int totalSum = 0;
        for (int x : arr) totalSum += x;


        if ((totalSum + diff) % 2 != 0 || totalSum < diff) {
            return 0;
        }

        int target = (totalSum + diff) / 2;
        int n = arr.size();

 
        vector<int> dp(target + 1, 0);
        
   
        dp[0] = 1;

        for (int num : arr) {
          
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] + dp[j - num];
            }
        }

        return dp[target];
    }
};