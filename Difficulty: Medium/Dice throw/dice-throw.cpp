class Solution {
  public:
int countRecur(int m, int n, int x, vector<vector<int>> &memo) {
    

    if (n==0 && x==0) return 1;
    
 
    if (n==0 || x<=0) return 0;
    
  
    if (memo[n][x] != -1) return memo[n][x];
    
    int ans = 0;
    
  
    for (int i=1; i<=m; i++) {
        ans += countRecur(m, n-1, x-i, memo);
    }
    
    return memo[n][x] = ans;
}

int noOfWays(int m, int n, int x) {
    
    vector<vector<int>> memo(n+1, vector<int>(x+1, -1));
    return countRecur(m, n, x, memo);
}
};