class Solution {
public:
int get_ans(vector<int> &nums,int &t,int curr,int i){
    if(i>=nums.size())return curr==t;
    return get_ans(nums,t,curr+nums[i],i+1)+get_ans(nums,t,curr-nums[i],i+1);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return get_ans(nums,target,0,0);
    
    }
};