// Last updated: 08/03/2026, 13:22:35




class Solution {
    public boolean canMakeEqual(int[] nums, int k) {
        int n=nums.length;

        int cst1=0;
        int currVal1=nums[0];
        for(int i=0;i<n-1;i++)
        {
            if(currVal1==-1) 
            {
                cst1++;
                currVal1 = -nums[i + 1];
            } else
            {
                currVal1=nums[i + 1];
            }
        }
        if(currVal1==1 &&cst1<=k) 
        {
            return true;
        }

        

        int cst2=0;
        int currVal2=nums[0];
        for(int i=0;i<n-1;i++){
            if(currVal2==1){
                cst2++;
                currVal2 = -nums[i + 1];
            } else 
            {
                currVal2 = nums[i + 1];
            }
        }
        if(currVal2==-1&&cst2<=k)
        
        {
            return true;
        }

        return false;
    }


    
}

