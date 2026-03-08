// Last updated: 08/03/2026, 13:22:18
class Solution {
public:
    
    int solveTwoChar(string &s, char x, char y) {
        unordered_map<int,int> mp;
        int diff = 0;
        int ans = 0;
        int start = 0;
        
        mp[0] = -1;
        
        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] != x && s[i] != y) {

                mp.clear();
                mp[0] = i;
                diff = 0;
                continue;
            }
            
            if(s[i] == x) diff++;
            else diff--;
            
            if(mp.count(diff))
                ans = max(ans, i - mp[diff]);
            else
                mp[diff] = i;
        }
        
        return ans;
    }
    
    int solveThreeChar(string &s) {
        unordered_map<long long,int> mp;
        mp[0] = -1;
        
        int a=0,b=0,c=0;
        int ans = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else c++;
            
            int d1 = a-b;
            int d2 = b-c;
            
            long long key = ((long long)d1 << 32) | (unsigned int)d2;
            
            if(mp.count(key))
                ans = max(ans, i - mp[key]);
            else
                mp[key] = i;
        }
        
        return ans;
    }
    
    int longestBalanced(string s) {
        
        int ans = 1;  
        
    
        int streak = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i-1]) streak++;
            else {
                ans = max(ans, streak);
                streak = 1;
            }
        }
        ans = max(ans, streak);

        ans = max(ans, solveTwoChar(s, 'a', 'b'));
        ans = max(ans, solveTwoChar(s, 'b', 'c'));
        ans = max(ans, solveTwoChar(s, 'a', 'c'));
       
        ans = max(ans, solveThreeChar(s));
        
        return ans;
    }
};