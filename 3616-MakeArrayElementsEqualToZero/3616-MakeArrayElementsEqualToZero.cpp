// Last updated: 08/03/2026, 13:23:45
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int leftSum = 0, cnt = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        for(int curr = 0;curr<nums.size();curr++){
            leftSum += nums[curr];
            rightSum -= nums[curr];
            if(nums[curr] == 0){
                int diff = rightSum - leftSum;
                if(diff == 1 or diff == -1)
                    cnt++;
                else if(diff == 0)
                    cnt += 2;
            }


            
        }
        return cnt;
    }
};