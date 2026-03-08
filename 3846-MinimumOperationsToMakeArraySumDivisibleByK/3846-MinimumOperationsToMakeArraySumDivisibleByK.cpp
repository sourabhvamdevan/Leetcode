// Last updated: 08/03/2026, 13:22:47
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return accumulate(nums.begin(),nums.end(),0)%k;
    }
};