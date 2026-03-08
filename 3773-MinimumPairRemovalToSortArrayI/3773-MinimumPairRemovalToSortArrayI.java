// Last updated: 08/03/2026, 13:23:05
class Solution {
    public int minimumPairRemoval(int[] nums) {
        int ops = 0;
        while (true){
            boolean nonDec=true;
            for(int i=0; i < nums.length - 1; i++){
                if(nums[i]>nums[i + 1]){
                    nonDec=false;
                    break;
                }
            }
            if(nonDec) return ops;
            
            if (nums.length < 2)return ops;
            
            int minSum = Integer.MAX_VALUE;
            int idx = -1;
            for(int i = 0;i < nums.length - 1; i++){
                int sum = nums[i]+nums[i + 1];
                if(sum < minSum){
                    minSum = sum;
                    idx = i;
                }
            }
            
            int[] newNums=new int[nums.length - 1];
            System.arraycopy(nums, 0, newNums, 0, idx);
            newNums[idx]=minSum;
            System.arraycopy(nums, idx + 2, newNums, idx + 1, nums.length - idx - 2);
            nums = newNums;


            
            ops++;
        }
    }
}