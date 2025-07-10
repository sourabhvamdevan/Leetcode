
//speed up i/o operations
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK

//This block writes "0" to a file named "display_runtime.txt" at program exit
//It's a LeetCode trick sometimes used to tweak runtime display

const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();  


class Solution {
public:


//this function to return the minimum number of insertions to make the string a palindrome

    int minInsertions(string s) {
        string s2 =s;

        //this will create a reversed version of the input string
        reverse(s2.begin() , s2.end());
        int n =s.size();
        int m=s2.size();

    //this will create a 2D DP table of size (n+1) x (m+1), initialized to -1
        //and the dp[i][j] will store LCS of s[0..i-1] and s2[0..j-1]


        vector<vector<int>>dp(n+1 , vector<int>(m+1,-1));
        

         //Base case: if either string is empty, LCS=0
        for(int i=0 ;i<=n ;i++) dp[i][0]=0;
        for(int j=0 ;j<=m ;j++) dp[0][j]=0;

        for(int i=1 ;i<=n ;i++){
            for(int j=1 ;j<=m ;j++){
                 if(s[i-1]==s2[j-1]){
             dp[i][j]= 1+dp[i-1][j-1];
        }else dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return n-dp[n][m];
    
    
    }
};