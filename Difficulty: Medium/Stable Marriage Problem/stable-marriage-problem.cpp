class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
      
        vector<int> manMatch(n, -1);
        

        vector<int> womanMatch(n, -1);
        
      
        vector<vector<int>> rank(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rank[i][women[i][j]] = j;
            }
        }
        
  
        vector<int> nextProposal(n, 0);
        
  
        vector<int> freeMen;
        for (int i=0;i<n;i++)freeMen.push_back(i);
        
        int freeCount = n;
        
        while (!freeMen.empty()) {
            int m = freeMen.back();
            freeMen.pop_back();
            
          
            int w = men[m][nextProposal[m]++];
            
         
            if (womanMatch[w] == -1) {
                womanMatch[w] = m;
                manMatch[m] = w;
            } else {
              
                int currentMan = womanMatch[w];
                
         
                if (rank[w][m] < rank[w][currentMan]) {
                    womanMatch[w] = m;
                    manMatch[m] = w;
                    
                  
                    manMatch[currentMan] = -1;
                    freeMen.push_back(currentMan);
                } else {
              
                    freeMen.push_back(m);
                }
            }
        }
        
        return manMatch;
    }
};