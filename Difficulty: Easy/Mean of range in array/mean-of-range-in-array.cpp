class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
          int n = arr.size();
    int q = queries.size();
    vector<int> result;
    
    vector<int> prefixSum(n + 1, 0);

    
    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    for (int i = 0; i < q; i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];

        
        int sum = prefixSum[r + 1] - prefixSum[l];
        int count = (r - l + 1);

    
        result.push_back(sum / count);
    }

    return result;
    }
};