class Solution {

    private:
    #define vi vector<int>
    #define pb push_back
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> a;
        for(int i:nums){
            a[i]++;

        }
priority_queue<pair<int,int>> q;
for(auto i:a){
    q.push({i.second,i.first});


}

vi ans;
for(int i=0;i<k;i++){
ans.pb(q.top().second);
q.pop();

}


return ans;

    }
};