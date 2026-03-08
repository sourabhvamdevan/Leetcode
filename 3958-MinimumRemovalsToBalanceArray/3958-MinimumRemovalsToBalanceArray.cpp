// Last updated: 08/03/2026, 13:22:26
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size(), maxSize = 0;
        sort(nums.begin(), nums.end());
        for(int left = 0; left < n; left++) {
            auto it = upper_bound(nums.begin(), nums.end(), 1LL * k * nums[left]);
            int right = it - nums.begin();
            maxSize = max(maxSize, right - left);
        }

        
        return n - maxSize;
    }
};