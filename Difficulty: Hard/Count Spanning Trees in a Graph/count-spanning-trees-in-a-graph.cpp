

class Solution {
public:

    double calculateDeterminant(vector<vector<double>>& matrix) {
        int sz=matrix.size();
        if (sz==0) return 1.0;
        double det=1.0;

        for(int i=0;i<sz;++i){
            int pivot=i;
            for (int j = i + 1; j < sz; ++j) {
                if (abs(matrix[j][i]) > abs(matrix[pivot][i])) pivot = j;
            }
            
            swap(matrix[i],matrix[pivot]);
            if (pivot != i) det *= -1;

            if (abs(matrix[i][i]) < 1e-9) return 0;

            det *= matrix[i][i];
            for (int j = i + 1; j < sz; ++j) {
                double factor = matrix[j][i] / matrix[i][i];
                for (int k = i + 1; k <sz;++k){
                    matrix[j][k] -= factor * matrix[i][k];
                }
                
                
                
    }
        }
        return det;
    }

    int countSpanTree(int n, vector<vector<int>>& edges) {
    
        if (n <= 1) return 1;

 
        vector<vector<double>> laplacian(n, vector<double>(n, 0));
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            laplacian[u][u]++;
            laplacian[v][v]++;
            laplacian[u][v]--;
            laplacian[v][u]--;
        }


        int mSize=n-1;
        vector<vector<double>> reduced(mSize, vector<double>(mSize));
        for (int i = 0; i < mSize; ++i) {
            for (int j = 0; j < mSize; ++j) {
                reduced[i][j] = laplacian[i][j];
            }
        }

        double result = calculateDeterminant(reduced);
        
    
        return (int)round(abs(result));
    }
};