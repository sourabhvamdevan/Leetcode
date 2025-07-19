class Solution {
private:
#define vs vector<string>
#define pb push_back



public:
    vector<string> removeSubfolders(vector<string>& fo) {
        vs ans;
        sort(fo.begin(),fo.end());
        ans.pb(fo[0]);
        string comp = fo[0];
        for(int i = 1 ;i<fo.size();i++){
            int len = comp.size();
            if(comp==fo[i].substr(0,len) && fo[i][len]=='/'){
                continue;
            }
            else{
                ans.pb(fo[i]);
                comp=fo[i];
            }


            
        }
        return ans;
    }
};