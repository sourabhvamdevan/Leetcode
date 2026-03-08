// Last updated: 08/03/2026, 13:22:24
class Solution {
public:



    int n,k;
    int expand(vector<int>& front, 
    vector<int>& nextFront,
    vector<int>& distHere, 
    vector<int>& distOther)
    
    {
        nextFront.clear();
        for (int cur : front){
            int off=n-cur;
            int lo = max(0, k - off);
            int hi = min(k, cur);
            for (int i = lo; i <= hi; i++) {
                int v = cur + k - 2 * i;
                if (distHere[v] == -1) {
                    distHere[v] = distHere[cur] + 1;
            if (distOther[v] != -1) return distHere[v] + distOther[v];
                    nextFront.push_back(v);
                }



    }
        }
        return -1;
    }
    int minOperations(string s, int k)
    {
        n = (int)s.size();
        this->k=k;
        int start=0;

        for (char c : s) start += c - '0';
        int target = n;
        if (start == target) return 0;
        vector<int> distA(n + 1, -1), distB(n + 1, -1);
        vector<int> frontA{start}, frontB{target};
        distA[start] = 0;
        distB[target] = 0;

        vector<int> nextA, nextB;
        while (!frontA.empty() && !frontB.empty()) {
            if (frontA.size() <= frontB.size()) {
                int meet = expand(frontA, nextA, distA, distB);
                if (meet != -1) return meet;
                frontA.swap(nextA);
            } else
            
            {
                int meet = expand(frontB, nextB, distB, distA);
                if (meet != -1) return meet;
                frontB.swap(nextB);
        }
    }
        return -1;
    }
};