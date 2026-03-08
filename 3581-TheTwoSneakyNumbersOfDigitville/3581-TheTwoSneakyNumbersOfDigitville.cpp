// Last updated: 08/03/2026, 13:23:53
#define vi vector<int>
#define pb push_back

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
vi ans, count(n);
   for(auto val:nums){
    count[val]++;
    if(count[val]==2) ans.pb(val);

   }


   return ans;

    }
};