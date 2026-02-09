class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        
        
        int lo= 0, hi=arr.size()-1;
        while(lo <=hi){
            
            if(arr[lo] <= arr[hi])
                
                return lo;
                
                int mid= lo+ (hi-lo)/2;
            if(arr[mid] > arr[hi])
              lo=mid+1;
              else
              hi=mid;
              
                
            
        }
        
        
        return lo;
    }
};
