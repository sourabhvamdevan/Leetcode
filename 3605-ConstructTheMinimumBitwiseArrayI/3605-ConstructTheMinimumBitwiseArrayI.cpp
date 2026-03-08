// Last updated: 08/03/2026, 13:23:49
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();

        for(int i=0;i<n; i++){
            int id =-1;

            for(int j=1; j<nums[i]; j++){

                if((j | (j+1))==nums[i]){
                    id=j;
                    break;

                }
            }

            ans.push_back(id);

        }


        return ans;
    }
};