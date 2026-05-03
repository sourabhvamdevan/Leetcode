// User function Template for C++

class Solution {
  public:
    int tileId = 1;

    void solve(int n, int row, int col, int missingR, int missingC, vector<vector<int>> &grid) {
        if (n == 1) return;

        int id = tileId++;
        int half = n / 2;
        int centerR = row + half;
        int centerC = col + half;

    
        if (missingR < centerR && missingC < centerC) {
        
            solve(half, row, col, missingR, missingC, grid);
        } else {
        
            grid[centerR - 1][centerC - 1] = id;
            solve(half, row, col, centerR - 1, centerC - 1, grid);
        }

  
        if (missingR < centerR && missingC >= centerC) {
            solve(half, row, centerC, missingR, missingC, grid);
        } else {
            grid[centerR - 1][centerC] = id;
            solve(half, row, centerC, centerR - 1, centerC, grid);
        }

   
        if (missingR >= centerR && missingC < centerC) {
            solve(half, centerR, col, missingR, missingC, grid);
        } else {
            grid[centerR][centerC - 1] = id;
            solve(half, centerR, col, centerR, centerC - 1, grid);
        }


        if (missingR >= centerR && missingC >= centerC) {
            solve(half, centerR, centerC, missingR, missingC, grid);
        } else {
            grid[centerR][centerC] = id;
            solve(half, centerR, centerC, centerR, centerC, grid);
        }
    }

    void fillTile(int n, vector<vector<int>> &grid) {
        int missingR = -1, missingC = -1;
        tileId = 1; 

      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) {
                    missingR = i;
                    missingC = j;
                    break;
                }
                
                
                
        }
            if (missingR != -1) break;
        }

        solve(n, 0, 0, missingR, missingC, grid);
    }
};