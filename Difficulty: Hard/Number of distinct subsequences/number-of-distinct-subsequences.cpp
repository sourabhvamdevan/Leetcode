class Solution {
public:
    int distinctSubseq(string &str) {
        int n=str.length();
        int mod=1e9 + 7;
        
 
        vector<long long> dp(n + 1);
        
   
        dp[0]=1;
        

        vector<int> last(26, -1);
        
        for(int i=1;i<=n;i++){
         
            dp[i] = (2 * dp[i - 1]) % mod;
            
            char current_char = str[i - 1];
            int last_idx = last[current_char - 'a'];
            
      
            if (last_idx != -1)
            
            {
                dp[i] = (dp[i] - dp[last_idx - 1] + mod) % mod;
            }
            
            
            
        
            last[current_char - 'a'] = i;
    }
        
        return (int)dp[n];
    }
};