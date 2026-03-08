// Last updated: 08/03/2026, 13:22:16
class Solution {
public:
    vector<int> rotateElements(vector<int>& A, int k) {
        int n = A.size();
        vector<int> pos;
        
        for(int& a : A) 
            if(a >= 0) pos.push_back(a);

        if(pos.empty())
            return A;
        
        k %= pos.size();
        rotate(begin(pos), begin(pos) + k, end(pos));

        int j = 0;
        
        for(int i = 0; i < n; ++i)
            if(A[i] >= 0)
                A[i] = pos[j++];

        return A;
    }
};