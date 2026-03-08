// Last updated: 08/03/2026, 13:22:54
class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n=nums.length;
        if(n<=2)return n;
        int target=n+1;
        int k=0;
        while((1<<k) <target){
            k++;
            
        }


        return 1<<k;
    }
}