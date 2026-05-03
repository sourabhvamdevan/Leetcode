class Solution {
public:
    string chooseandswap(string str) {
        set<char> s;

        for (char ch:str)s.insert(ch);

        for (int i = 0; i < str.size(); i++) {
  
            s.erase(str[i]);

            if(s.empty()) break;


            char smallest = *s.begin();

            if (smallest < str[i]) {
                char c1 = str[i];
                char c2 = smallest;


                for (int j = 0; j < str.size(); j++) {
                    if (str[j] == c1) str[j] = c2;
                    else if (str[j] == c2) str[j] = c1;
                }
                break;
            }
            
            
            
            
        }
        return str;
    }
};