class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        
        cin.tie(0) ->sync_with_stdio(false);
        int n=arr.size();
        vector<int> res;
        
      
        int catalan[]={1, 1, 2, 5, 14, 42, 132};
        
        for (int i = 0; i < n; i++) {
            int leftCount = 0;
            int rightCount = 0;
            
           
            for (int j = 0; j < n; j++)
            
            {
                if (i == j) continue;
                if (arr[j] < arr[i]) {
                    leftCount++;
                } else {
                    rightCount++;
    }
            }
            
            
            res.push_back(catalan[leftCount] * catalan[rightCount]);
        }
        
        return res;
    }
};