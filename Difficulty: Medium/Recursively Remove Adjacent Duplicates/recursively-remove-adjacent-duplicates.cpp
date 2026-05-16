// User function template for C++


class Solution {
  public:
    string removeUtil(string &s) {
        string res = "";
        int n=s.length();
        int i=0;

        while(i<n){
         
            if (i < n - 1 && s[i] == s[i + 1]) {
          
                while (i < n - 1 && s[i] == s[i + 1]) {
                    i++;
                }
              
                i++; 
            } else
            
            {
             
                res+=s[i];
                i++;
            }
            
            
        }


        if (res.length() == s.length()) {
            return res;
        }

     
        return removeUtil(res);
    }
};