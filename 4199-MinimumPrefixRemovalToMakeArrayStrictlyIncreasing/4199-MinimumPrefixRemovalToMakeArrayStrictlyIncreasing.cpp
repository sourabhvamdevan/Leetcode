// Last updated: 08/03/2026, 13:22:15
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int idx = -1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] >= nums[i + 1]){
                idx = i;
            }
        }
        if(idx == -1){
            return 0;
        }
        return idx + 1;
    }
};