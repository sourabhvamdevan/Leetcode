class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n = a.size();
  
 
    sort(a.begin(), a.end());

    int minDiff = INT_MAX;

    for (int i = 0; i + m - 1 < n; i++) {
      	
      
        int diff = a[i + m - 1] - a[i];
      
    
        if (diff < minDiff)
        	minDiff = diff;
    }
    return minDiff;
        
    }
};