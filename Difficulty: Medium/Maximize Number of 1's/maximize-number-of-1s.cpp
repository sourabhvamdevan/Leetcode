class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int l=0,r=0;
        int maxLen=0;
        int zeroCnt=0;
        while(r<arr.size()){
            if(arr[r]==0){
                zeroCnt++;
                
                
            }
            
            while(zeroCnt>k){
                if(arr[l]==0){
                    zeroCnt--;
                    
                }
                
                l++;
                
            }
            
            maxLen=max(maxLen,r-l+1);
            r++;
            
        }
        
        return maxLen;
    }
};
