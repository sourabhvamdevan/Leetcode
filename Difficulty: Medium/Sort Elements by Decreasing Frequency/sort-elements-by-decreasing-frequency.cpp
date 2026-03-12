class Solution {
  public:
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

      
        vector<pair<int, int>> elements;
        for (auto& p : freq) {
            elements.push_back({p.first, p.second});
        }

      
        sort(elements.begin(), elements.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second; 
            } else {
                return a.first < b.first;  
            }
        });

  
        vector<int> result;
        for (auto& p : elements) {
            result.insert(result.end(), p.second, p.first);
        }

        return result;
    }
};