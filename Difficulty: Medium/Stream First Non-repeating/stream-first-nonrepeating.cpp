class Solution {
  public:
    string firstNonRepeating(string &s) {
   
      string ans = "";

    vector<int> count(26, 0);
    
    queue<char> q;

    for (int i = 0; i < s.length(); i++) {
        
       
        if (count[s[i] - 'a'] == 0) {
            q.push(s[i]);
        }
        count[s[i] - 'a']++;

       
        while (!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();
        }

       
        if (!q.empty()) {
            ans += q.front();
        }
        else {
            ans += '#';
        }
        
        
        
    }

    return ans;
   
   
   
        
    }
};