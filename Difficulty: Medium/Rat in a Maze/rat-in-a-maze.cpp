class Solution {
    void solve(int i, int j, vector<vector<int>>& maze, int n, vector<string>& ans, string move) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }

        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, +1, 0};
        string dir = "DLRU";

        for (int idx = 0; idx < 4; idx++) {
            int nexti = i + di[idx];
            int nextj = j + dj[idx];

            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && maze[nexti][nextj] == 1) {
                maze[i][j] = 0; 
                solve(nexti, nextj, maze, n, ans, move + dir[idx]);
                maze[i][j] = 1; 
            }
        }
    }

public:
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        if (n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0) return ans;

        solve(0, 0, maze, n, ans, "");
        return ans;
    }
};