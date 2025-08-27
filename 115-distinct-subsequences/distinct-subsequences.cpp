#define vvi vector<vector<int>>
#define vi vector<int>
#define vd vector<double>

class Solution {
public:
    int numDistinct(string s, string t) {
       int n=s.size();
       int m=t.size();
       vd prev(m+1,0);
       prev[0]=1;
       for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(s[i-1]==t[j-1]){
prev[j]+=prev[j-1];
            }
        }
       } 


       return (int) prev[m];
    }
};