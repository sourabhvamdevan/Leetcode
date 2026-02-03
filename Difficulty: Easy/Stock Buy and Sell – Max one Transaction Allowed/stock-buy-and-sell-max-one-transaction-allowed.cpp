class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
     
     
     
     
       int minSoFar = prices[0], res = 0;
  
    for (int i = 1; i < prices.size(); i++) {

  
        minSoFar = min(minSoFar, prices[i]);
       
                    
        res = max(res, prices[i] - minSoFar);
    }
    return res;
        
    }
};
