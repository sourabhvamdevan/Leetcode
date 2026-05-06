class Solution {
public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
      
        int startX=knightPos[0] - 1;
        int startY=knightPos[1] - 1;
        int targetX=targetPos[0] - 1;
        int targetY=targetPos[1] - 1;

        if (startX==targetX && startY==targetY)return 0;

      
        int dx[]={-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[]={1, 2, 2, 1, -1, -2, -2, -1};


        queue<pair<pair<int, int>, int>> q;
        q.push({{startX, startY}, 0});

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[startX][startY] = true;

        while (!q.empty()) {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int steps=q.front().second;
            q.pop();

       
    for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            
                if (nx == targetX && ny == targetY) {
                    return steps + 1;
                }

             if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, steps + 1});
    }
            }
        }
        
        

        return -1; 
    }
};