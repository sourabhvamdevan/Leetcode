class Solution {
public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        int n = a.size();
        vector<int> diff;
        long long totalProfit=0;

        for(int i=0;i<n;i++){
            totalProfit += b[i]; 
            diff.push_back(a[i] - b[i]);
        }


        sort(diff.begin(), diff.end(), greater<int>());

      
        
        for (int i = 0; i < x; i++) {
          
            if (diff[i] > 0 || i < (n - y)) {
                totalProfit += diff[i];
            } else {
                break;
            }
        }

        return (int)totalProfit;
    }
};