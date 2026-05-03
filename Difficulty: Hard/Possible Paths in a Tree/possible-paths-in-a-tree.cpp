// User function template for C++

class Solution {
  public:

    int find(int i, vector<int> &parent)
    {
        if (parent[i]==i) return i;
        return parent[i]=find(parent[i], parent);
    }


    int Union(int i, int j, vector<int> &parent, vector<int> &sz) {
        int root_i=find(i, parent);
        int root_j = find(j, parent);
        
        if (root_i != root_j) {
         
            int new_paths = sz[root_i] * sz[root_j];
            
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            
            return new_paths;
        }
        return 0;
    }

    vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries) {
   
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

   
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> parent(n + 1);
        vector<int> sz(n + 1, 1);
        for (int i=1;i<=n;i++) parent[i] = i;

        vector<int> ans(q);
        int currentWeightIndex = 0;
        int totalPaths = 0;

        for (int i = 0; i < q; i++) {
            int queryVal = sortedQueries[i].first;
            int queryIdx = sortedQueries[i].second;

      
            while (currentWeightIndex < n - 1 && edges[currentWeightIndex][2] <= queryVal) {
                totalPaths += Union(edges[currentWeightIndex][0], edges[currentWeightIndex][1], parent, sz);
                currentWeightIndex++;
            }
            ans[queryIdx] = totalPaths;
        }

        return ans;
    }
};