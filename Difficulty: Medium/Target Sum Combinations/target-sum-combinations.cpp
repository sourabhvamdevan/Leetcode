class Solution {
  public:
    void findCombinations(int index, int target, vector<int>& arr, vector<int>& current, vector<vector<int>>& result) {
    
        if (target==0){
            result.push_back(current);
            return;
        }

        for(int i=index;i<arr.size();i++){
          
            if(arr[i]>target)break;

         
            current.push_back(arr[i]);
            
       
            findCombinations(i, target - arr[i], arr, current, result);
            
       
            current.pop_back();
        }
        
        
        
    }

    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
       
        sort(arr.begin(),arr.end());
        
        findCombinations(0, target, arr, current, result);
        return result;
    }
};