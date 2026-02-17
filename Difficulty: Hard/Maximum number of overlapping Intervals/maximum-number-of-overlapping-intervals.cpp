class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr)
    {
        // code here
        
        
        int maxi=-1;
     

    for(int i=0;i<arr.size();i++){
        maxi = max(maxi, max(arr[i][0],arr[i][1]));
    }
    
 
    vector<int> v(maxi+1, 0);
    for(int i=0;i<arr.size();i++){
        
   
        v[arr[i][0]] += 1;
        if(arr[i][1]<maxi){
            v[arr[i][1] + 1] -= 1;
        }
        
        
        
    }
    

    for(int i=1;i<v.size();i++){
        v[i] += v[i-1];
    }
    return *max_element(v.begin(),v.end());
    }
    
    
    
};
