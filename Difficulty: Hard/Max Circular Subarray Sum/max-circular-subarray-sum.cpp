class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
    
    
     int n = arr.size();
    int suffixSum = arr[n - 1];
    

    vector<int> maxSuffix(n + 1, 0);
    maxSuffix[n - 1] = arr[n - 1];
    
    for(int i = n - 2; i >= 0; i--) {
        suffixSum = suffixSum + arr[i];
        maxSuffix[i] = max(maxSuffix[i + 1], suffixSum);
    }
    
 
    int circularSum = arr[0];
    
  
    int normalSum = arr[0];
    
    int currSum = 0;
    int prefix = 0;
    
    for(int i = 0; i < n; i++) {
        
    
        currSum = max(currSum + arr[i], arr[i]);
        normalSum = max(normalSum, currSum);
      

        prefix = prefix + arr[i];
        circularSum = max(circularSum, prefix + maxSuffix[i+1]);
    }
    
    return max(circularSum, normalSum);
        
    }
};