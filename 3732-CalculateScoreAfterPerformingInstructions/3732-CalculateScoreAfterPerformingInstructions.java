// Last updated: 08/03/2026, 13:23:14
class Solution {
    public long calculateScore(String[] instructions, int[] values) {
        long score=0;
        Set<Integer> visited=new HashSet<>();
        int i=0;
        int n=instructions.length;

        while(i>=0 && i<n){
            if(visited.contains(i)){
                break;
            }

            visited.add(i);
            String instruction=instructions[i];
            if(instruction.equals("add")){


                score+=values[i];

                i++;

                
            }

            else if(instruction.equals("jump")){
                i+=values[i];
                
            }
        }



        return score;
    }
}