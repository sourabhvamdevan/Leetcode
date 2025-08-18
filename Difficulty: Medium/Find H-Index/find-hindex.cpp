class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> buckets(n + 1, 0);

        for (int c : citations) {
            if (c >= n)
                buckets[n]++;
            else
                buckets[c]++;
        }

        int cumulative = 0;
        for (int i = n; i >= 0; --i) {
            cumulative += buckets[i];
            if (cumulative >= i)
                return i;
        }
        
        
        return 0;
    }
};