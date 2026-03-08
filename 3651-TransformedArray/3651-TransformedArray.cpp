// Last updated: 08/03/2026, 13:23:27
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);

        for(int i=0; i<n; i++){
            int targetidx = ((i+ nums[i]) % n+n) % n;
            res[i]= nums[targetidx];

        }

        return res;
    }
};