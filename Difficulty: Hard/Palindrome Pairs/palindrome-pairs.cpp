class Solution {
public:
    bool isPalindrome(string& s) {
        int l=0,r=s.length()-1;
        while(l<r){
            if (s[l++] != s[r--]) return false;
        }
        
        
        return true;
    }

    bool palindromePair(vector<string>& arr)
    
    {
        int n=arr.size();
        if (n<2) return false;

        unordered_map<string, int> dict;
        for(int i=0;i<n;i++){
            dict[arr[i]]=i;
        }

        for(int i=0;i<n;i++){
            string s = arr[i];
            int len = s.length();

            for (int j = 0; j <= len; j++) {
         
                string prefix = s.substr(0, j);
                string suffix = s.substr(j);

            
                if (isPalindrome(prefix)) {
                    string revSuffix = suffix;
                    reverse(revSuffix.begin(), revSuffix.end());
                    if (dict.count(revSuffix) && dict[revSuffix] != i) {
                        return true;
                    }
                }

            
                if (suffix.length() > 0 && isPalindrome(suffix)) {
                    string revPrefix = prefix;
                    reverse(revPrefix.begin(), revPrefix.end());
                    if (dict.count(revPrefix) && dict[revPrefix] != i) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};