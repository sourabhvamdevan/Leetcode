// User function Template for C++

class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
                     
                     {
        
   
        if (source.first==destination.first && source.second==destination.second) {
            return 0;
        }

        int n=grid.size();
        int m=grid[0].size();

      
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
    
        queue<pair<int, pair<int, int>>> q;

   
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

    
        int dr[]={-1, 1, 0, 0};
        int dc[]={0, 0, -1, 1};

        while (!q.empty())
        
        {
            auto it=q.front();
            q.pop();

            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

   
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

           
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && 
                    grid[nr][nc] == 1 && d + 1 < dist[nr][nc]) {
                    
                    dist[nr][nc] = d + 1;

                
                    if (nr == destination.first && nc == destination.second) {
                        return d + 1;
                    }
                    
                    q.push({d + 1, {nr, nc}});
                }
                
                
                
            }
        }

        return -1; 
    }
};