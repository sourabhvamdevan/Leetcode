class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
      
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> result;
        int n=arr.size();

        for(int i=0;i<n;i++)
        {
         
            if(minHeap.size()<k){
                minHeap.push(arr[i]);
            }else if(arr[i]>minHeap.top()) {
            
                minHeap.pop();
                minHeap.push(arr[i]);
            }
            
            
            

       
            if(minHeap.size()<k){
                result.push_back(-1);
            } else
            
            {
       
                result.push_back(minHeap.top());
    }
            
            
}

        return result;
    }
};