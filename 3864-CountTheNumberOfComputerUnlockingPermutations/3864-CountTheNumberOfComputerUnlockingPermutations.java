// Last updated: 08/03/2026, 13:22:45
class Solution {
    long MOD=1_000_000_007;

    public int countPermutations(int[] complexity) {
        int n=complexity.length;

        boolean[] unlockable=new boolean[n];
        boolean[] isPlaced=new boolean[n];

        unlockable[0]=true;

        long ans=1;
        int placedCnt=0;

        while(placedCnt<n){
            
            List<Integer> available=new ArrayList<>();
            for(int i=0;i<n;i++){
                
                if(unlockable[i]&&!isPlaced[i]){
                    
                    available.add(i);
                }

                
            }

            if(available.isEmpty()){

                
                return 0;
            }

            long k=available.size();
            long factorialK=1;
            for(int i=1;i<=k;i++){
                
                factorialK=(factorialK*i)%MOD;
                
            }
            ans=(ans * factorialK) % MOD;

            placedCnt+=k;
            if(placedCnt==n){
                
                break;

                
            }

            for(int computerIdx:available){

                
                isPlaced[computerIdx] = true;
            }

            for(int i=0;i<n;i++){
                if(!unlockable[i]){
                    for(int j:available){
                        if(j<i&&complexity[j]<complexity[i]){
                            unlockable[i]=true;
                            break;
                        }
                    }
                    
                }

                
            }

            
        }

        return (int) ans;
    }
    
}
