class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        
        
        int n=q.size();
        vector<int> arr(n);
        for(int i =0; i<n; i++){
            arr[i]=q.front();
            q.pop();
            
            
        }
        
        for(int i=0; i<n/2; i++){
            
            
            q.push(arr[i]);
            q.push(arr[i+n/2]);
            
        }
        
    }
};