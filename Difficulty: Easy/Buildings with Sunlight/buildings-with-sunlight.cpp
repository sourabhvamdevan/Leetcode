class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int ans=1;
        int maxi=arr[0];
        for(int i=1;i<arr.size();i++){
            
            
            if(arr[i]>=maxi){
                
                ans++;
                
                maxi=arr[i];
                
                
            }
            
            
        }
        
        
        return ans;
    }
};