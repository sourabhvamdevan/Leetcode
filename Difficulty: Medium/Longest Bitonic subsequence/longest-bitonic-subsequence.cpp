class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        if(n<3)return 0;

        vector<int> lis(n, 1);
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i] && lis[i] < lis[prev] + 1) {
                    lis[i] = lis[prev] + 1;
                }
                
                
                
            }
        }

   
        vector<int> lds(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int next = n - 1; next > i; next--) {
                if (nums[next] < nums[i] && lds[i] < lds[next] + 1) {
                    lds[i] = lds[next] + 1;
                }
                
                
                
            }
        }

        int maxLBS=0;
        for (int i = 0; i < n; i++)
        {
   
            if (lis[i] > 1 && lds[i] > 1)
            
            {
                maxLBS = max(maxLBS, lis[i] + lds[i] - 1);
            }
        }

        return maxLBS;
    }
};