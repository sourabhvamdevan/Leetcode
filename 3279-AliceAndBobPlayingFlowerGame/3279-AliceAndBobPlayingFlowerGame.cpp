// Last updated: 08/03/2026, 13:24:32
#define ll long long
class Solution {
public:
    long long flowerGame(int n, int m) {
        ll ans=0;
        for(int i=1;i<=n;i++){
            int res=0;
            if(i%2==0) res=(m+1)/2;
            else res=m/2;
            ans+=res;

        }

         return ans;

    }
};