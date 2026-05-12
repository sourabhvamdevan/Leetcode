class Solution {
public:
  
    long long getGCD(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }


    long long getLCM(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / getGCD(a, b)) * b;
    }






    void build(int node, int start, int end, vector<int>& arr, vector<long long>& tree) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, arr, tree);
        build(2 * node + 1, mid + 1, end, arr, tree);
        tree[node] = getLCM(tree[2 * node], tree[2 * node + 1]);
    }






    void update(int node, int start, int end, int idx, int val, vector<long long>& tree) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid=(start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val, tree);
        else
            update(2 * node + 1, mid + 1, end, idx, val, tree);
        
        tree[node] = getLCM(tree[2 * node], tree[2 * node + 1]);
    }





  
    long long query(int node, int start, int end, int L, int R, vector<long long>& tree) {
        if (R < start || end < L) return 1; 
        if (L <= start && end <= R) return tree[node];

        int mid = (start + end) / 2;
        long long leftLCM = query(2 * node, start, mid, L, R, tree);
        long long rightLCM = query(2 * node + 1, mid + 1, end, L, R, tree);
        
        return getLCM(leftLCM, rightLCM);
    }
    
    
    
    
    

    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        vector<long long> tree(4 * n);
        vector<long long> results;

        build(1, 0, n - 1, arr, tree);

        for (auto& q : queries)
        
        {
            if (q[0] == 1) { 
                update(1, 0, n - 1, q[1], q[2], tree);
            } else { 
                results.push_back(query(1, 0, n - 1, q[1], q[2], tree));
            }
        }

        return results;
    }
};