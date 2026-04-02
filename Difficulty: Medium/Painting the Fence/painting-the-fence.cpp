class Solution {
  public:
    int countWays(int n, int k) {
      
        if (n == 1) return k;
        
      
        long long prev2 = k;            
        long long prev1 = (long long)k * k; 
        
        if (n == 2) return (int)prev1;
        
        long long current;
        for (int i = 3; i <= n; i++) {
          
            current = ((k - 1) * (prev1 + prev2));
            
       
            prev2 = prev1;
            prev1 = current;
        }
        
        return (int)prev1;
    }
};