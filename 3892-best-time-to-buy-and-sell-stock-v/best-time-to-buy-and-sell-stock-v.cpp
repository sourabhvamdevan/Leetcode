#include<vector>
#include<algorithm>
using namespace std;


class Solution {

    private:
    #define ll long long
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<long long> prev(n,0),curr(n,0);

        for(int t=1;t<=k; t++){
          ll bestLong=-prices[0];
          ll bestShort=prices[0];

          curr[0]=0;
          for(int i=1;i<n;i++){
            ll res=curr[i-1];
            res=max(res,(ll)prices[i]+bestLong);
            res=max(res,-(ll)prices[i]+bestShort);
            curr[i]=res;

            bestLong=max(bestLong,prev[i-1]-(ll)prices[i]);
            bestShort=max(bestShort,prev[i-1]+(ll) prices[i]);


          }  


          prev.swap(curr);

        }


        return prev[n-1];
    }
};