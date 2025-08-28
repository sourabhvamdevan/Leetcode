class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lelo1=INT_MAX,lelo2=INT_MAX, bechdo1=INT_MIN, bechdo2=INT_MIN;
        for(int i=0;i<prices.size();i++){
            lelo1=min(lelo1,prices[i]);
            bechdo1=max(bechdo1,prices[i]-lelo1);
            lelo2=min(lelo2,prices[i]-bechdo1);
            bechdo2=max(bechdo2,prices[i]-lelo2);
        }

        return bechdo2;
    }
};