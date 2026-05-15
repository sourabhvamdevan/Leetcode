

class Solution {
public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        if (K == 0) return N;


        vector<int> freq(26, 0);
        for (char t : tasks) {
            freq[t - 'A']++;
        }

    
        sort(freq.begin(), freq.end(), greater<int>());

        int max_freq = freq[0];
        

        int count_max_freq = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == max_freq) {
                count_max_freq++;
            } else
            
            {
                break; 
            }
        }

      
        int ans = (max_freq - 1) * (K + 1) + count_max_freq;

      
        return max(ans, N);
    }
};