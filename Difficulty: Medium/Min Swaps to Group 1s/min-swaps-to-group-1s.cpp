class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n=arr.size();
        int totalOnes=0;

     
        for(int x:arr){
            if(x==1)totalOnes++;
        }

     
        if(totalOnes==0)return -1;

      
int currentOnes=0;
int maxOnesInWindow=0;

    for(int i=0;i<n;i++){
        
        
         
            if(arr[i]==1)currentOnes++;

  
    if(i>=totalOnes){
             
                if(arr[i-totalOnes]==1)currentOnes--;
            }

        
            if (i>=totalOnes - 1){
                maxOnesInWindow=max(maxOnesInWindow, currentOnes);
    }
        }

      
        return totalOnes - maxOnesInWindow;
    }
};