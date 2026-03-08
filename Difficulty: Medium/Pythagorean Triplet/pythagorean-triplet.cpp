class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        
     	int n = arr.size();
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(arr[i]);

  	
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
          	
          	int a = arr[i];
          	int b = arr[j];
          
         
            int c=sqrt(a * a + b * b);
            
        
            if (c*c == a*a + b*b && st.find(c) != st.end())
                return true;
    }
    }
  

    return false;
    }
};