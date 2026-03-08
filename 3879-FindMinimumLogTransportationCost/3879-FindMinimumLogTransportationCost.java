// Last updated: 08/03/2026, 13:22:34
class Solution {
    public long minCuttingCost(int n, int m, int k) {
        if(n<=k && m<=k){
            return 0; 
        }else if(n>k&& m<=k){
            return (long) (n - k)*k; 
        } else 
        {
            return (long) (m - k) * k; 
        }

        
    }
}