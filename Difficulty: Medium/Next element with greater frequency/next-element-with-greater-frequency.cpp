class Solution {
public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int val : arr) freq[val]++;  

        vector<int> res(n, -1);
        stack<int> st; 

        
        for (int i = n - 1; i >= 0; --i) {
           
            while (!st.empty() && freq[st.top()] <= freq[arr[i]]) {
                st.pop();
            }

            if (!st.empty()) {
                res[i] = st.top(); 
            }

            st.push(arr[i]); 
        }
        
        
        

        return res;
    }
};

