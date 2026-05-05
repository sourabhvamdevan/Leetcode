class Solution {
public:
    long long sumXOR(vector<int> &arr) {
        long long totalSum = 0;
        int n=arr.size();

 
        for (int i = 0; i < 32; i++){
            long long count1=0; 
            
            for(int j=0;j<n;j++){
                if (arr[j] & (1 << i))
                {
                    count1++;
                }
                
                
                
            }
            
      
            long long count0=n-count1;
            
         
            totalSum+=(count1 * count0) * (1LL << i);
        }

        return totalSum;
    }
};