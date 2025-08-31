class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 10007);
        dist[k] = 0;
        for(int i=0;i<n-1;i++) {
           for(int i=0;i<times.size();i++) {
            if(dist[times[i][0]] + times[i][2] < dist[times[i][1]] )
                dist[times[i][1]] = dist[times[i][0]] + times[i][2];
            } 
        }
        int mx = 0;
        for(int i=1;i<=n;i++) {
            mx = max(mx, dist[i]);
        }
        return mx == 10007 ? -1 : mx;
        
        
    }
};