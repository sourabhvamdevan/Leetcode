
#define f(i,n) for(int i=0;i<n;i++)


class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        // int n=arr.size();
        // int cnt=n;
        
        // f(i,n){
        //   int mini =arr[i];
        //  for(int j=i+1; j<n; j++){
             
             
        //      mini= min(mini, arr[j]);
             
        //      if(mini >= arr[i]){
        //          cnt++;
                 
        //      }else{
                 
                 
        //          break;
                 
        //      }
        //  }
           
            
        // }
        
        
        
        // return cnt;
        
        stack<int> st;
        
        int ans=0;
        int n=arr.size();
        
        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() and arr[st.top()]>=  arr[i])
            
            st.pop();
            
            int last = (st.empty() ? n: st.top());
            
            ans+= (last -i);
            
            
            st.push(i);
            
            
        }
        
        
        
        
        return ans;
        
        
    }
};