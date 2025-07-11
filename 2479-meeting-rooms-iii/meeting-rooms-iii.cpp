class Solution {

    private:
    #define ll long long
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        sort(m.begin(),m.end());

        vector<long long> time(n,0);
        vector<int> cnt(n,0);

        for(auto& m: m){
            int start=m[0], end=m[1];
            int assigned=-1;
            for(int i=0;i<n;i++){
                if(time[i]<=start){
                    time[i]=end;
                    cnt[i]++;
                    assigned=i;
                    break;

                }
            }

            if(assigned==-1){
                int idx=0;
                ll minEnd=time[0];
                for(int i=1;i<n;i++){
                    if(time[i]<minEnd){
                        minEnd=time[i];
                        idx=i;

                    }
                }
time[idx]+=(end-start);
cnt[idx]++;


     

        }
     }
    int maxCnt=0, res=0;
     for(int i=0; i<n; i++){
        if(cnt[i]>maxCnt){
            maxCnt=cnt[i];
            res=i;





            }
        }



        return res;

    }
};