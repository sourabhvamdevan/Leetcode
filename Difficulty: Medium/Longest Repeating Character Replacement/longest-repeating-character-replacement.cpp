class Solution {
public:
    int longestSubstr(string& s, int k) {
        int n=s.length();
        vector<int> counts(26, 0); 
        
        int left=0;
        int max_freq=0;
        int max_length = 0;
        
        for (int right = 0; right < n; right++) {

            counts[s[right] - 'A']++;
            
 
            max_freq = max(max_freq, counts[s[right] - 'A']);
            
    
            while ((right - left + 1) - max_freq > k) {
                counts[s[left] - 'A']--;
                left++;
              
            }
            
            
        
            max_length=max(max_length, right - left + 1);
        }
        
        return max_length;
    }
};