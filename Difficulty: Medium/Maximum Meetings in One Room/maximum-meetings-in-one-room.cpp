class Solution {
  public:

    struct Meeting {
        int start;
        int end;
        int index;
    };

    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        int n=s.size();
        vector<Meeting> meetings(n);

        for(int i=0;i<n;i++){
            meetings[i]={s[i], f[i], i + 1};
        }

      
        sort(meetings.begin(), meetings.end(), [](const Meeting &a, const Meeting &b) {
            if (a.end != b.end) {
                return a.end < b.end;
            }
            return a.index < b.index;
        });

        vector<int> result;
        if (n == 0) return result;

        int last_finish_time = -1;

        for(int i=0;i<n;i++){
            if (meetings[i].start > last_finish_time)
            
            
            {
                result.push_back(meetings[i].index);
                last_finish_time = meetings[i].end;
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};