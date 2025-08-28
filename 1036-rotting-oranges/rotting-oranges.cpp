#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vpii vector<pair<int, int>>


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vvb vis (n, vector<bool> (m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = true;
                }


            }
        }

        int count = -1;
        vpii dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        while(!q.empty()) {
            int size = q.size();
            count++;
            for(int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if(grid[row][col] == 1) {
                    grid[row][col] = 2;
                }

                for(auto [dx, dy]: dir) {
                    int nx = row + dx, ny = col + dy;
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m 
                        && !vis[nx][ny] && grid[nx][ny] == 1) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    } 


                }
            }
        }

        for(int row=0;row<n;row++){

            for(int col = 0; col < m; col++) {
                if(grid[row][col]==1){
                    return -1;
                }


            }
        }
        if(count == -1) return 0;
        return count;
    }

};