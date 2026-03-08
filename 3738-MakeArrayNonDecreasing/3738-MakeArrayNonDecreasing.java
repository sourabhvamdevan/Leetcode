// Last updated: 08/03/2026, 13:23:13
class Solution {
    public int maximumPossibleSize(int[] nums) {
        Stack<Integer> stack=new Stack<>();
        for(int num:nums){
            while(!stack.isEmpty() && num<stack.peek()){
                int popped=stack.pop();
                num=Math.max(num,popped);
                
            }


            stack.push(num);
            
        }


        return stack.size();

        
    }
}