class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
         vector<int> res; 
    int m = a.size();
    int n = b.size();
  
    int i = 0, j = 0;    
    while(i < m && j < n)
    {
      
        
        if(i > 0 && a[i - 1] == a[i]) {
            i++;
            continue;
        }
      
        
        if(a[i] < b[j]) {
            i++;
        }
        else if(a[i] > b[j]) {
            j++;
        }
      
        
        else
        
        {
            res.push_back(a[i]);
            i++;
            j++;
        }
    }
    return res; 
    }
};