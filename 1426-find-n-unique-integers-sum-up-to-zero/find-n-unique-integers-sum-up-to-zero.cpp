#define vi vector<int>
#define pb push_back

class Solution {
public:
    vector<int> sumZero(int n) {
        vi res;
if(n==0) return res;
if(n%2!=0) res.pb(0);
for(int i=1;i<=floor(n/2);i++){
    res.pb(i);
    res.pb(-i);

}

return res;

    }
};