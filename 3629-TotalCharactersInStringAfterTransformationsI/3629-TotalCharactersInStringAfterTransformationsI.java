// Last updated: 08/03/2026, 13:23:37
class Solution {
    public int lengthAfterTransformations(String s, int t) {
        int MOD=1_000_000_007;
        int[] v=new int[26];
        for(char ch:s.toCharArray()){
            v[ch-'a']++;

        }

        for(int i=0;i<t;i++){

            int elem=v[25];
            for(int j=25;j>0;j--){
                v[j]=v[j-1];


            }

            v[0]=0;
            v[0]=(v[0]+elem) %MOD;

            v[1]=(v[1]+elem) % MOD;



        }

        int sum=0;
        for(int i=0;i<26;i++){
            sum=(sum+v[i]) % MOD;

        }


        return sum;
        
    }
}