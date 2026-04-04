class Solution {
  public:
    vector<string> graycode(int n) {

        vector<string> result = {"0", "1"};
        
    
        if (n == 1) return result;
        
     
        for (int i = 2; i <= n; i++)
        {
         
            int currentSize = result.size();
            for (int j = currentSize - 1; j >= 0; j--) {
                result.push_back(result[j]);
            }
            
            
            for(int j=0;j<result.size();j++){
                if (j < currentSize) {
                    result[j] = "0" + result[j];
                } else
                {
                    result[j] = "1" + result[j];
             }
            }
        }
        
        return result;
    }
};