class Solution {
  public:
    void relativeSort(vector<int>& a1, vector<int>& a2) {
   
        map<int, int> freq;
        for (int x : a1) {
            freq[x]++;
        }

        vector<int> result;


        for (int x : a2) {
            if (freq.find(x) != freq.end()) {
            
                int count = freq[x];
                while (count--)
                
                {
                    result.push_back(x);
                }
                
                
                
             
                freq.erase(x);
            }
        }

   
        for (auto const& [val, count] : freq) {
            int c = count;
            while (c--) {
                result.push_back(val);
            }
        }

   
        a1 = result;
    }
};