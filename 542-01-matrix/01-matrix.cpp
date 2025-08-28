class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();       
        int m = mat[0].size();      
        vector<vector<int>> dis(n, vector<int>(m, -1));  
        queue<pair<int, int>> q;    
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});        
                    dis[i][j] = 0;         
                }
            }
        }

        int delRow[4] = {1, -1, 0, 0};
        int delCol[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && dis[nrow][ncol] == -1) {
                    dis[nrow][ncol] = dis[row][col] + 1;  
                    q.push({nrow, ncol});                
                }
            }
        }

        return dis;
    }
};