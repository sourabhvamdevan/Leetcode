

class Solution {
public:
    int countPS(string &s) {
        int n = s.size();
        int count = 0;

        
        auto expand = [&](int left, int right) {
            int c = 0;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) 
                    c++;
                left--;
                right++;
            }
            return c;
        };

        
        for (int i = 0; i < n; i++) {
            count += expand(i, i);     
            count += expand(i, i + 1); 
        }

        return count;
    }
};


