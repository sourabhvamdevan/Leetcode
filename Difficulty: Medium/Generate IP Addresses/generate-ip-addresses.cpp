class Solution {
  public:
    vector<string> generateIp(string &s) {
        // code here
           vector<string> result;
        int n = s.length();
        

        if (n < 4 || n > 12) return result;
        

        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
            
                    int l = n - i - j - k;
                    if (l < 1 || l > 3) continue;
                    
                 
                    string a=s.substr(0, i);
                    string b=s.substr(i, j);
                    string c=s.substr(i + j, k);
                    string d=s.substr(i + j + k, l);
                    
                    
                    if(isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
                        result.push_back(a + "." + b + "." + c + "." + d);
                 }
                }
    }
        }
        
        return result;
        
    }
    
      private:
    bool isValid(const string &part) {
        
        if (part.length() > 1 && part[0] == '0') return false;
        
        
        int num = stoi(part);
        
        
        return num >= 0 and num <= 255;
    }
};