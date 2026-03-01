class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int cnt=0;
        
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]!=0)
            
            arr[cnt++] =arr[i];
            
        }
        
        while(cnt < arr.size())
        arr[cnt++]=0;
    }
};