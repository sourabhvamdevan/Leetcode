#define pb push_back


class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        cin.tie(0) ->sync_with_stdio(false);
        // code here
        
        
        set<int> st;
        for(int i=0; i<a.size(); i++)
        st.insert(a[i]);
        
        for(int i=0; i< b.size(); i++)
        
        st.insert(b[i]);
        
        vector<int> res;
        
        for(auto it: st)
        res.pb(it);
        
        return res;
        
    }
};