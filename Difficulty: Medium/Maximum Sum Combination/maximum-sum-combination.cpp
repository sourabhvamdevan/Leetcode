class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n=a.size();
        vector<int> result;

       
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());

       
        priority_queue<pair<int, pair<int, int>>> maxHeap;

       
        set<pair<int, int>> visited;

     
        maxHeap.push({a[0] + b[0], {0, 0}});
        visited.insert({0, 0});

        
        while (k-- && !maxHeap.empty()) {
            auto top = maxHeap.top(); maxHeap.pop();
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;

            result.push_back(sum);

         
            if (i + 1 < n && visited.find({i + 1, j}) == visited.end()) {
                maxHeap.push({a[i + 1] + b[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

           
            if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
                maxHeap.push({a[i] + b[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return result;
    }
};
