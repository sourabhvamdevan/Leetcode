class Solution {
  public:
    int smallestSubstring(string s) {
        int last0 = -1,last1=-1,last2=-1;
        int minLength = INT_MAX;
        int n=s.length();

        for (int i = 0; i < n; i++){
            if (s[i] == '0') last0 = i;
            else if (s[i] == '1') last1 = i;
            else if (s[i] == '2') last2 = i;

      
            if (last0 != -1 && last1 != -1 && last2 != -1) {
            
                int currentMin = min({last0, last1, last2});
                minLength = min(minLength, i - currentMin + 1);
            }
            
            
}

        
        return (minLength == INT_MAX) ? -1 : minLength;
    }
};
