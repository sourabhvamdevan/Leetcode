class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int lo=0, hi=arr.size()-1;
        while(lo<=hi){
int mid=lo+(hi-lo)/2;


if(arr[mid]==k){
    return mid;
    
    
}

else if(arr[mid]<k){
    
    lo=mid+1;
    
}

else {
    
    hi=mid-1;
    
}
            
        }
        
        
        return lo;
    }
};