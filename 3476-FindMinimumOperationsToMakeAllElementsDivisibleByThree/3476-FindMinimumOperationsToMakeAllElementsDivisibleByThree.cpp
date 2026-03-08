// Last updated: 08/03/2026, 13:24:08
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        for(auto ele:nums){
        if(ele%3!=0){
            cnt++;

        }
        }

        return cnt;
    }
};