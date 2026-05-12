// User function Template for C++



class Solution {
public:
    int minThrow(int N, int arr[]) {
    
        vector<int> board(31, -1);
        for(int i=0;i<2*N;i+=2){
            board[arr[i]]=arr[i + 1];
        }

        queue<pair<int, int>> q; 
        vector<bool> visited(31, false);

        q.push({1,0});
        visited[1]=true;

        while (!q.empty())
        
        {
            pair<int, int> curr = q.front();
            q.pop();

            int u=curr.first;
            int dist=curr.second;

        
            if (u == 30) return dist;

          
            for(int dice=1;dice<=6;++dice){
                int v = u + dice;

                if (v <= 30)
                
                {
                 
                    if (board[v] != -1)
                    
                    {
                        v = board[v];
                    }

                    if (!visited[v])
                    
                    {
                        visited[v]=true;
                        q.push({v, dist + 1});
                    }
                    
                    
                    
        }
            }
        }

    return -1; 
    }
};