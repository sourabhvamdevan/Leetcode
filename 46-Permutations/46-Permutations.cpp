// Last updated: 08/03/2026, 13:33:20
1
2
3class Solution {
4public:
5    vector<vector<int>> permute(vector<int>& nums)
6    {
7        vector<vector<int>> res;
8        backtrack(nums, 0, res);
9        return res;
10
11    }
12
13    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res) {
14        if (start == nums.size()) {
15            res.push_back(nums);
16            return;
17        }
18
19        for (int i = start; i < nums.size(); i++)
20        {
21            swap(nums[start], nums[i]);
22            backtrack(nums, start + 1, res);
23            swap(nums[start], nums[i]);
24        }
25
26
27    }
28    
29    void swap(int& a, int& b) {
30        int temp = a;
31        a = b;
32        b = temp;
33    }    
34
35
36};