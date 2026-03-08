// Last updated: 08/03/2026, 13:22:22
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
   cin.tie(0) -> sync_with_stdio(false);


        int n=nums.size();

        int ans=0;

        for(int i=0; i<n; i++){
  unordered_set<int> odd;
  unordered_set<int> even;
  for(int j=i; j<n; j++){

    if(nums[j] % 2){
        odd.insert(nums[j]);
    }
    else{

        even.insert(nums[j]);

    }
   if(odd.size()==even.size()){
    ans=max(ans, j-i+1);

   }


  }

        }


        return ans;
    }
};