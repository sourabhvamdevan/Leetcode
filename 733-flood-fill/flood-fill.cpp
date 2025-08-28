class Solution {
public:
    void dfs(vector<vector<int>>& mat,int i,int j,int color,int r,int c,int cellColor){
     
        if(i<0 || i>=r || j<0 || j>=c || mat[i][j] != cellColor){
            return;
        }
        
        
        mat[i][j] = color;
        
        
        dfs(mat,i-1,j,color,r,c,cellColor);
        dfs(mat,i+1,j,color,r,c,cellColor);
        dfs(mat,i,j+1,color,r,c,cellColor);
        dfs(mat,i,j-1,color,r,c,cellColor);
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& mat, int sr, int sc, int color) {
        int r=mat.size();
        int c=mat[0].size();
        
        int cellColor = mat[sr][sc];
        if(cellColor == color)return mat;
        
        dfs(mat,sr,sc,color,r,c,cellColor);
        return mat;
    }
};