class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MIN, no=INT_MIN;
        int coolDown=0, sell=0;
        for(int p:prices){
            no=max(no,buy);
            buy=coolDown-p;
            coolDown=max(coolDown,sell);
            sell=no+p;

        }


        return max(coolDown,sell);
    }
};