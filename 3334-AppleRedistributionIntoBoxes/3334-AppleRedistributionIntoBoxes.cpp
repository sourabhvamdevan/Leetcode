// Last updated: 08/03/2026, 13:24:25
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        for(auto i:apple) sum+=i;
        sort(capacity.begin(), capacity.end());
        int n=capacity.size();
        int ans=0;
       for(int i=n-1;i>=0;i--){
        sum-= capacity[i];
        ans++;
        if(sum<=0) break;

       
       } 

       return ans;
    }

};
