

class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;
        
        
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? i : i - s.top() - 1;
            s.push(i);
        }
        
        
        while (!s.empty()) s.pop();
        
        
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n - 1 - i : s.top() - i - 1;
            s.push(i);
        }
        
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (long long)arr[i] * (left[i] + 1) * (right[i] + 1);
            sum %= MOD;
        }
        
        
        
        return (int)sum;
    }
};