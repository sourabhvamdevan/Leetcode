class Solution {
public:

    bool isValid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

    
    vector<string> validParenthesis(string &s) {
        vector<string> result;
        if (s.empty()) return {""};

        queue<string> q;
        set<string> visited;
        
        q.push(s);
        visited.insert(s);
        
        bool found = false;

        while (!q.empty()) {
            int size = q.size();
            set<string> level_results; 

            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    level_results.insert(curr);
                    found = true;
                }

                if (!found) {
                    for (int j = 0; j < curr.length(); ++j) {
                        if (curr[j] != '(' && curr[j] != ')') continue;

                        string next = curr.substr(0, j) + curr.substr(j + 1);
                        if (visited.find(next) == visited.end()) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }

            if (found) {
                for (const string& str : level_results) {
                    result.push_back(str);
                }
                sort(result.begin(), result.end());
                return result;
            }
        }

        if(result.empty()) return {""};
        return result;
    }
};