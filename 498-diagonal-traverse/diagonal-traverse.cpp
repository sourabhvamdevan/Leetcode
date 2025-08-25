class Solution {
    private:
    #define vi vector<int>
    #define mvi map<int,vector<int>>
    #define pb push_back
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
       vi res;
mvi mp;
for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[i].size();j++){
        mp[i+j].pb(matrix[i][j]);

    }
}

for(auto i:mp){
    if(i.first%2==0){
        for(int j=i.second.size()-1;j>=0;j--)
        res.pb(i.second[j]);

    }else{
        for(int j=0;j<i.second.size();j++)
        res.pb(i.second[j]);

    }
}



return res;
    }
};