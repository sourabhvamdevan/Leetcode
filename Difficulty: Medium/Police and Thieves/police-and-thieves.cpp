class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n=arr.size();
        int i=0, j=0;
        int cnt=0;
        while( i < n and j <n){
            
        while(i < n and arr[i] != 'P') i++;
        while(j < n and arr[j] != 'T') j++;
        
        if(i < n and j < n and abs(i-j)<=k){
            
            cnt++;
            i++;
             j++;
             
             
        }
        
        else if(j < n and j< i) {
             j++;
             
             
        }
        
        else if(i < n and i< j) {
             i++;
             
             
        }
            
        }
        
        
        return cnt;
        
        
        
    }
};