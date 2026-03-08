// Last updated: 08/03/2026, 13:22:41
#define ll long long

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mod=1e9+7;
        ll ans=1;
        for(int i=1;i<complexity.size(); i++){

            if(complexity[0]<complexity[i]) ans=(ans*i) %mod;

            else return 0;

        }


        return ans;
    }
};