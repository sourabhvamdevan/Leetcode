// Last updated: 08/03/2026, 13:23:54
class Solution {

    private:
    #define ll long long
public:
    bool isVowel(char a){
        return a=='a'||a=='i'||a=='o'||a=='e'||a=='u';
    }
    ll f(string word, int k){
        if(k<0) return 0;
        unordered_map<char,ll> mp;
        ll vCount=0,totalVCount = 0;
        ll i=0,j=0;
        ll n = word.size();
        ll res = 0;
        while(j<n){
            if(isVowel(word[j])){
                totalVCount++;
                if(mp.find(word[j])!=mp.end()){
                    if(mp[word[j]]<i){
                    vCount++;
                    }
                    mp[word[j]]=j;
                }
                else if(mp.find(word[j])==mp.end()){
                    mp[word[j]]=j;
                    vCount++;
                }
            }
            while((j-i+1 - totalVCount)>k){
                if(isVowel(word[i])){
                    if(mp[word[i]]==i) vCount--;
                    totalVCount--;
                }
                i++;
            }
            if(vCount==5){
                int x = min({mp['a'],mp['e'],mp['i'],mp['o'],mp['u']});
                res+=(x-i+1);
            }
            j++;
        }
        return res;
    }
    ll countOfSubstrings(string word, int k) {
        return f(word,k)-f(word,k-1);
    }
};