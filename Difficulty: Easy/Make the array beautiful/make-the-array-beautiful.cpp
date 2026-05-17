class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> st; 
        
        for (int num : arr) {
            if (st.empty()) {
                st.push_back(num);
            } else
            
            
            {
               
                if ((st.back() >= 0 && num < 0) || (st.back() < 0 && num >= 0)) {
                    st.pop_back();
                } else
                
                
                {
                    st.push_back(num); 
    }
}
}
        
        return st;
    }
};