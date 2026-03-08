// Last updated: 08/03/2026, 13:23:25
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<long long> pre(n, 0);

        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];
        vector<long long> A;
        for (int i = 0; i <= n - k; i++)
        {
            long long cur = pre[i + k - 1] - (i > 0 ? pre[i - 1] : 0);
            A.push_back(cur);
        }

        // dp
        long long res = -1e18;
        vector<long long> dp(A.size(), 0);

        for (int i = 0; i < A.size(); i++)
        {
            dp[i] = A[i];
            if (i >= k)
            {
                dp[i] = max(dp[i], A[i] + dp[i - k]);
            }
            res = max(res, dp[i]);
        }

        

        return res;
    }
};