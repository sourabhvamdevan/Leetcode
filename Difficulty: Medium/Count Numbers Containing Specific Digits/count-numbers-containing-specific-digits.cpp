

class Solution {
public:
    int countValid(int n, vector<int>& arr) {
        unordered_set<int> forbidden(arr.begin(),arr.end());

        vector<int> allowedDigits;
        for(int d=0;d<=9;++d){
            
            if(forbidden.find(d)==forbidden.end()){
                
                allowedDigits.push_back(d);
            }
            
            
        }

        int totalNDigitNumbers=9 * pow(10, n - 1);

       
        if(allowedDigits.empty())return totalNDigitNumbers;

        int countInvalid=0;

       
        for(int d:allowedDigits){
            
            
            if(d==0)continue;

           
            int ways=1;

            for(int i=1;i<n;i++){
                
                ways *= allowedDigits.size();
            }
            
            

            countInvalid += ways;
        }

       
       
       
        return totalNDigitNumbers-countInvalid;
    }
};
