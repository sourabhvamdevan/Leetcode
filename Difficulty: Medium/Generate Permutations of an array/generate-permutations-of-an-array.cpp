class Solution {
  public:
    
    void permutations(vector<vector<int>>& res, vector<int> arr, int idx) {
    if (idx == arr.size()) {
        res.push_back(arr);
        return;
    }


    for (int i = idx; i < arr.size(); i++) {
      
        
        swap(arr[idx], arr[i]);


        permutations(res, arr, idx + 1);

  
        swap(arr[idx], arr[i]);
    }
}


vector<vector<int>> permuteDist(vector<int>& arr) {
    vector<vector<int>> res;
    permutations(res, arr, 0);
    return res;
}
    
    
    
    
};