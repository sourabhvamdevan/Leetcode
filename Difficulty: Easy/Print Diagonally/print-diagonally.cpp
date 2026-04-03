class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        vector<int> result;
        
    
        for (int sum = 0; sum < 2 * n - 1; sum++) {
           
            int start_row = max(0, sum - (n - 1));
            int end_row = min(sum, n - 1);
            
            for (int i = start_row; i <= end_row; i++) {
                int j = sum - i;
                result.push_back(mat[i][j]);
            }
        }
        
        return result;
    }
};