class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> st;
        
        for (int x : arr){
            bool destroyed=false;
            
            while (!st.empty() && ((st.back() > 0 && x < 0) || (st.back() < 0 && x > 0))) {
                int top = st.back();
                
                if (abs(x) > abs(top)) {
                
                    st.pop_back();
                } else if(abs(x)==abs(top))
                
                {
                   
                    st.pop_back();
                    destroyed = true;
                    break;
                } else
                
                
                {
                 
                    destroyed = true;
                    break;
                }
            }
            
            if(!destroyed){
                st.push_back(x);
            }
            
            
            
        }
        
        return st;
    }
};