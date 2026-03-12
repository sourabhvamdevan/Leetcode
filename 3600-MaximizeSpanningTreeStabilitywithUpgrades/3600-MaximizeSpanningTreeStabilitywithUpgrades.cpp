// Last updated: 12/03/2026, 19:09:54
1class Solution {
2public:
3    class DSU {
4private:
5    vector<int> parent, sizes;
6
7public:
8    DSU(int n) {
9        parent.resize(n);
10        sizes.resize(n, 1);
11        for (int i = 0; i < n; ++i)
12            parent[i] = i;
13    }
14
15    int find(int x) {
16        if (parent[x] != x)
17            parent[x] = find(parent[x]);
18        return parent[x];
19    }
20
21    void unite(int x, int y) {
22        int xr = find(x);
23        int yr = find(y);
24        if (xr == yr) return;
25
26        if (sizes[xr] < sizes[yr]) swap(xr, yr);
27        parent[yr] = xr;
28        sizes[xr] += sizes[yr];
29    }
30    
31    int getSize(int x) {
32        return sizes[find(x)];
33    }
34};
35
36    int maxStability(int n, vector<vector<int>>& edges, int k) {
37        vector<vector<int> >msts;
38        vector<vector<int> >nmsts;
39        for(int i=0;i<edges.size();i++){
40            int u =edges[i][0],v=edges[i][1],s=edges[i][2],must=edges[i][3];
41            if(must==1)msts.push_back({u,v,s});
42            else nmsts.push_back({s,u,v});
43        }
44        int mustans=1e9;
45        int nmustans=1e9;
46        DSU d(n);
47        for(int i=0;i<msts.size();i++){
48            int u=msts[i][0],v=msts[i][1],s=msts[i][2];
49            if(d.find(u)==d.find(v))return -1;
50            d.unite(u,v);
51            mustans=min(mustans,s);
52        }
53        sort(nmsts.begin(),nmsts.end());
54        reverse(nmsts.begin(),nmsts.end());
55        vector<int>nans;
56        for(int i=0;i<nmsts.size();i++){
57            int s=nmsts[i][0],u=nmsts[i][1],v=nmsts[i][2];
58            if(d.find(u)==d.find(v))continue;
59            d.unite(u,v);
60            nans.push_back(s);
61        }
62        sort(nans.begin(),nans.end());
63        for(int i=0;i<nans.size();i++){
64            if(k>0){
65                nans[i]*=2;
66                k--;
67            }
68        }
69        sort(nans.begin(),nans.end());
70        int finalans=1e9;
71        finalans=min(finalans,mustans);
72      if(not nans.empty())  finalans=min(finalans,nans[0]);
73        if(d.getSize(0)!=n)return -1;
74        return finalans;
75    }
76};