// Last updated: 10/03/2026, 19:32:09
1class Solution {
2public:
3    int maxProfit(vector<int>& pri) {
4        int maxSourabh=0;
5        int minPrice=INT_MAX;
6
7        for(int i=0;i<pri.size();i++)
8        
9        {
10            minPrice=min(minPrice,pri[i]);
11            maxSourabh=max(maxSourabh,pri[i]-minPrice);
12        }
13
14
15        return maxSourabh;
16    }
17};