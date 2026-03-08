// Last updated: 08/03/2026, 13:23:46
class Solution {
public:
    int find(vector<int>& nums, int i, int j, int x) {
        int sum=0;

        vector<int> v(51, 0);
        priority_queue<pair<int, int>> pq;

        for(; i<j;i++)
        
        {
            v[nums[i]]++;
        }



        for (int i = 0; i < 51; i++) {
            if (v[i] > 0)
                pq.push({v[i], i});
        }

        while (!pq.empty() && x > 0) {
            sum += pq.top().second * pq.top().first;
            pq.pop();
            x--;
        }




        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res;

        if (x >= k) {
            for (int i = k; i <= n; i++) { 
                res.push_back(
                    accumulate(nums.begin() + i - k, nums.begin() + i, 0));
            }
        } else
        
        {
            for (int i = k; i <= n; i++) {
                int s = find(nums, i - k, i, x);
                res.push_back(s);
            }




        }

        return res;
    }
};