// Last updated: 08/03/2026, 13:23:32
class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int n=nums.length;
        //yeh diff arr ko initiliaze krega 
        int[] diff=new int[n + 1];

        //yeh each queries ko process krega 
        for(int[] q:queries){
            int l=q[0];
            int r=q[1];
            
            diff[l]++; //this will mark the start of the range by incrementing diff;


            //this will mark the 
            if(r+1<diff.length){
                diff[r + 1]--;
            }


        }

        int sum=0;
        //yeh iteration krega for each element 
        for(int i=0;i<n;i++){
            //yeh prefix sum compute krega 
            sum+=diff[i];
            
            if(nums[i]>sum){
                return false;
            }
        }




        //sare elements ko reduce krega to zaro
        return true;
    }
}
