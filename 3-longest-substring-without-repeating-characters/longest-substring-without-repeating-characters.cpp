class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,l=0,r=0;
        int  n =s.size();
        vector<int> map(256,-1);
        while(r<n){
            if(map[s[r]]!=-1){
                l=max(map[s[r]]+1,l);
            }
            map[s[r]]=r;
            ans= max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};