// Last updated: 08/03/2026, 13:22:43
class Solution {
    public boolean canPartitionGrid(int[][] grid) {

        long totalSum = 0;
        long rowSum = 0;
        long colSum = 0;
        int n = grid.length;
        int m = grid[0].length;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                totalSum += grid[i][j];
            }
        }

        if(totalSum % 2 == 1) return false;

        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                rowSum += grid[i][j];
            }
            if(rowSum == (totalSum/2)) return true;
        }

        for(int i=0; i<m-1; i++){
            for(int j=0; j<n; j++){
                colSum += grid[j][i];
            }
            if(colSum == (totalSum/2)) return true;
        }

        return false;
        
    }
}