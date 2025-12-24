class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        vector<int> res;
        
        sort(arr.begin(),arr.end());
        for(auto & q: queries){
            
            int a=q[0];
            int b=q[1];
int cnt=upper_bound(arr.begin(), arr.end(),b)-lower_bound(arr.begin(),arr.end(),a);
res.push_back(cnt);

}
     return res;   
        
    }
};