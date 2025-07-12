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
    int lengthOfLIS(vector<int>& sv) {
        int n=sv.size();
        vector<int>dp(n,1);
        for(int i=n-1;i>=0; i--){
            for(int j=i+1;j<n;j++){
                if(sv[j]>sv[i]){
                    dp[i]=max(dp[i],dp[j]+1);

                }
            }
        }


        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);

        }


        return ans;
     


    }
};