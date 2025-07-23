class Solution {
public:
int sourabh(vector<int> &nums, int &t, int curr,int i){
    if(i>=nums.size())return curr==t;
  return sourabh(nums,t,curr+nums[i],i+1)+sourabh(nums,t,curr-nums[i],i+1);  
}
    int findTargetSumWays(vector<int>& nums, int target) {
       return sourabh(nums,target,0,0);

    
    }
};