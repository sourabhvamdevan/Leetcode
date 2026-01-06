class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        int xr = 0;

       
        for (int i = 0; i < k; i++)
            xr ^= arr[i];

        int ans = xr;

       
        for (int i = k; i < n; i++) {
            xr ^= arr[i];      
            xr ^= arr[i - k]; 
            ans = max(ans, xr);
        }
        
        

        return ans;
    }
};
