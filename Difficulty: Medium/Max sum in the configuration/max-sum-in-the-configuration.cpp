class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();


    int curSum=0;
    for (int i = 0; i < n; i++)
        curSum += arr[i];

 
    int currVal=0;

    for (int i = 0; i < n; i++)
        currVal += i * arr[i] ;


    int res=currVal ;


    for (int i = 1; i < n; i++)
    
    {

  
        int nextVal = currVal - (curSum - arr[i - 1]) + 
                        arr[i - 1] * (n - 1);


        currVal = nextVal;


        res = max(res, nextVal);
    }

    return res;
        
        
    }
};