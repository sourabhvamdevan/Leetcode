class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        queue<int> flips;
        int operations = 0;

        for (int i = 0; i < n; i++) {
            
            while (!flips.empty() && flips.front() <= i - k) {
                flips.pop();
            }

          
            int currentBit = arr[i] ^ (flips.size() % 2);

            if (currentBit == 0)
            {
            
                if (i + k > n) return -1; 
                flips.push(i);
                operations++;
    }
        }

        return operations;
    }
};