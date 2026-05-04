// User function Template for C++

class Solution {
public:
    int maximumPath(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
          if (n == 1) {
            int max_val = mat[0][0];
            for (int j = 1; j < m; j++) {
                max_val = max(max_val, mat[0][j]);
            }
            return max_val;
        }


        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = mat[i - 1][j];
                int left_diag = (j > 0) ? mat[i - 1][j - 1] : 0;
                int right_diag = (j < m - 1) ? mat[i - 1][j + 1] : 0;
                
                mat[i][j] += max({up, left_diag, right_diag});
            }
        }


        int max_sum=0;
        for (int j = 0; j < m; j++) {
            max_sum = max(max_sum, mat[n - 1][j]);
        }

        return max_sum;
    }
};