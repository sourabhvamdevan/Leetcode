class Solution {
  public:
    bool findTriplets(vector<int> &arr) {
        // code here
        
        
        int n=arr.size();
        
        if(n<3)return false;
        
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n-2; i++){
            
            int j= i+1, k=n-1;
            
            while(j<k){
                
    int sum =arr[i] + arr[j] +arr[k];
    
    if(sum ==0){
        
        
        return true;
        
    }
    
    else if(sum <0){
        
        j++;
        
        
        
    }else {
        
        
        k--;
        
        
    }
            }
        }
        
        return false;
    }
};