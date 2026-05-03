// User function Template for C++

class Solution {
  public:
    // Function to check if we can reach the last index from 0th index.
    bool canReach(vector<int> &arr) {
        // code here
        int reachable=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
     //edge case        
    if(i>reachable)return false;
    
    reachable=max(reachable,i+arr[i]);
    
    if( reachable>=n-1)return true;
    
    
    
            
            
        }
        
        
        
        
        return true;
        
    }
};