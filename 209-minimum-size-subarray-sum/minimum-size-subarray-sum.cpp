class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,len,minLen=INT_MAX,sum=0, n=nums.size();
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                len=j-i+1;
                minLen=min(len,minLen);
                sum-=nums[i];
                i++;

            }

            j++;

        }


        if(minLen==INT_MAX) return 0;
        return minLen;
    }
};