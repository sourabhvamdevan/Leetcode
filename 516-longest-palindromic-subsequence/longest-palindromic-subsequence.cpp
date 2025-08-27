
#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
public:

    int longestPalindromeSubseq(string s) {
      
int n=s.size();
string a=s;
string b=s;
reverse(b.begin(),b.end());
vvi dp(n+1,vi(n+1,0));
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(a[i-1]==b[j-1])
        dp[i][j]=1+dp[i-1][j-1];
        else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
}


return dp[n][n];

    }

    
};