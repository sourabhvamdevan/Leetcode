class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        
        
        for (int j=0; j < cols; j++){
            int val = mat[0][j];
            for (int i = 1, k = j + 1; i < rows && k < cols; i++, k++) {
                if (mat[i][k] != val) return false;
            }
        }
        
        
        for (int i = 1; i < rows; i++) {
            int val = mat[i][0];
            for (int j = 1, k = i + 1; j < cols && k < rows; j++, k++) {
                if (mat[k][j] != val) return false;
            }
        }
        
        return true;
    }
};