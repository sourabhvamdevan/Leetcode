// Last updated: 08/03/2026, 13:22:39
import java.util.stream.IntStream;

class Solution {
    public int smallestIndex(int[] nums) {
        return IntStream.range(0, nums.length)
            .filter(i->digitSum(nums[i])==i)
            .findFirst()
            .orElse(-1);
    }
    
    private int digitSum(int num){
        int s=0;
        while(num>0) {
            s+=num%10;
            num/=10;
        }

        
        return s;
    }
}