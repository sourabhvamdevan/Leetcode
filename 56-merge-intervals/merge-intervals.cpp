class Solution {
    private:
    #define vi vector<int>
    #define vvi vector<vector<int>>
    #define pb push_back
public:

static bool comparator(vi& a, vi& b){
    return a[0]<b[0];

}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vvi res;
       if(intervals.empty()){
        return res;

       }

       if(intervals.size()==1){
        res.pb(intervals[0]);
        return res;

       }

   sort(intervals.begin(),intervals.end(),comparator);

   res.pb(intervals[0]);
   int i=1;
   while(i<intervals.size()){
    vi &last=res.back();
    if(last[1]<intervals[i][0]){
        res.pb(intervals[i]);

    }  else{
        last[1]=max(last[1],intervals[i][1]);

    }   i++;

   }    


      return res;  
    }
};