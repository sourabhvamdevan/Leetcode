class Solution {
  public:
  
  
int maxSumSub(vector<int> &arr) {

int n    =arr.size();
    
    int sum = 0;
    int ans = 0;
    
    for (int i=0; i<n; i++) {
        sum += arr[i];
        ans = max(ans, sum);
        
 
        if (sum < 0) sum = 0;
    }
    
    return ans;
}


int maxOnes(vector<int> &arr) {
    int n = arr.size();
    
    int oneCnt = 0;
    
    
    for (int i=0; i<n; i++) {
        if (arr[i] == 1) {
            arr[i] = -1;
            oneCnt++;
        }
        else arr[i] = 1;
    }
    

    int maxDiff = maxSumSub(arr);
    
    
    return oneCnt + maxDiff;
}
};