class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        int n=arr.size();
        if (n <= 1) return 0;


        long long hold=-arr[0];
        long long free = 0;

        for (int i = 1; i < n; i++)
        {
         
            long long next_free=max(free, hold + arr[i] - k);
            
       
            long long next_hold=max(hold, free - arr[i]);

            free=next_free;
            hold=next_hold;
        }

      
        return (int)free;
    }
};