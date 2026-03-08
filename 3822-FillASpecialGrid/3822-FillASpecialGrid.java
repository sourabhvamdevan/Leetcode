// Last updated: 08/03/2026, 13:22:56
class Solution {
    public int[][] specialGrid(int N) {
        int size=1<<N;
        int[][] grid=new int[size][size];
        fillGrid(grid, 0, 0, N, 0);  return grid;
        
    }


    
    private void fillGrid(int[][]grid,int row,int col,int N,int start) {
        if(N==0){
            grid[row][col]=start;
            return;
        }


        
        
        int size=1<<(N - 1);
        int totalNumbers=size*size;
        
        fillGrid(grid,row,col + size, N - 1,start);
        
        fillGrid(grid, row + size, col + size, N - 1, start + totalNumbers);
        fillGrid(grid, row + size, col, N - 1, start + 2 * totalNumbers);
        fillGrid(grid, row, col, N - 1, start + 3 * totalNumbers);

        
    }
}