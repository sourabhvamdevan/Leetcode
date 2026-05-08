class Solution {
public:
    int minimumNumberOfSwaps(string& s) {
        int balance=0;
        int swaps=0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') {
                balance++;
            } else {
                balance--;
            }

            if (balance < 0) {
                int j = i + 1;
                while (j < n && s[j] != '[') {
                    j++;
                }
                
                swaps += (j - i);
                
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                
                balance = 1; 
            }
        }
        return swaps;
    }
};