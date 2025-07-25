class Solution {

    private:
    #define uii unordered_map<int,int>
public:
    int numIdenticalPairs(vector<int>& A) {
        int res=0;
        uii cnt;
        for(int a:A){
            res+= cnt[a]++;

        }

        return res;

    }
};