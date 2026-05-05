class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        int n=cost.size();
   
        long long INF=1e15;
        vector<long long> dp(w + 1, INF);

   
        dp[0]=0;

      
        for(int j=1;j<=n;++j){
            int packetCost=cost[j - 1];
            
        
            if (packetCost != -1) {
           
                for (int weight = j; weight <= w; ++weight) {
                    if (dp[weight - j] != INF) {
                        dp[weight] = min(dp[weight], dp[weight - j] + packetCost);
                    }
                    
                    
                    
    }
            }
        }

        return (dp[w] == INF) ? -1 : (int)dp[w];
    }
};