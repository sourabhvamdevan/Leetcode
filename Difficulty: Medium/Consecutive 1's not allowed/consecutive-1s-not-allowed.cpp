class Solution {
  public:
    int countStrings(int n) {
        long long a=1;
        long long b=1; 
        
        for (int i = 2; i <= n; i++)
        {
            long long temp = a;
            a = a + b;
            b = temp;
    }
        
        return (int)(a + b);
    }
};