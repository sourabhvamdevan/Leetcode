// User function Template for C++



class Solution {
public:
    void solve(int start, string& s, unordered_set<string>& wordSet, vector<string>& currentWords, vector<string>& result) {
       
        if (start == s.length()) {
            string sentence = "";
            for (int i = 0; i < currentWords.size(); i++) {
                sentence += currentWords[i];
                if (i != currentWords.size() - 1) sentence += " ";
            }
            result.push_back(sentence);
            return;
        }

   
        string temp = "";
        for (int j = start; j < s.length(); j++) {
            temp += s[j];
            
         
            if (wordSet.count(temp)) {
                currentWords.push_back(temp);
                solve(j + 1, s, wordSet, currentWords, result);
              
                currentWords.pop_back();
            }
            
            
        }
    }

    vector<string> wordBreak(vector<string>& dict, string s){
        unordered_set<string> wordSet(dict.begin(), dict.end());
        vector<string> result;
        vector<string> currentWords;
        
        solve(0, s, wordSet, currentWords, result);
        return result;
    }
};