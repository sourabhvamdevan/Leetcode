class Solution {
  public:
    int countSetBits(int n) {
        if (n == 0) {
            return 0;
        }

        long long total_set_bits = 0;
        for (long long p = 1; p <= n; p *= 2) {
            long long cycles = (n + 1) / (2 * p); 
            total_set_bits += cycles * p; 
            
            long long remainder = (n + 1) % (2 * p);
            
            total_set_bits += max(0LL, remainder - p);
        }

        return (int)total_set_bits;
        
    }
};
