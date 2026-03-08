// Last updated: 08/03/2026, 13:22:33
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,long> leftCount, rightCount;
        for(auto &val: nums) rightCount[val]+=1;

        long ans=0, mod=1e9+7, n=nums.size(), target;

        for(int i=0;i<n;i++){

target=nums[i]*2;
rightCount[nums[i]]-=1;
ans=(ans+(leftCount[target]*rightCount[target]))%mod;
leftCount[nums[i]]+=1;



        }

        return ans%mod;
    }
};