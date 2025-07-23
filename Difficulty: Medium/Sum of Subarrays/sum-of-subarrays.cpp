class Solution {
    private:
    #define ll long long
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        ll total=0;
        int n=arr.size();
        for(int i=0;i<n; ++i){
        total+=static_cast<ll> (arr[i])*(i+1)*(n-i);
        
        }
        
        return total;
    }
};