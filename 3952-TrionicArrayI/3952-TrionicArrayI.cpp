// Last updated: 08/03/2026, 13:22:28
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int ind=1, N=nums.size();
        bool left=false, right=false, center=false;

        while(ind < N and nums[ind-1]<nums[ind]){
            left=true;
            ind++;

        }

        while(ind <N && nums[ind-1] > nums[ind]){
            center =true;
            ind++;

        }

    while(ind < N and nums[ind-1] < nums[ind]){
        right=true;
        ind++;
    }

    return left and center and right and ind==N;
    }
    
};