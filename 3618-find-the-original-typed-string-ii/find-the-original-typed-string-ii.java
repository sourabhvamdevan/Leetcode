class Solution {

    private static final int mod=1000000007;

    public int possibleStringCount(String word, int k) {
        int n=word.length();
        int cnt=1;
        List<Integer> freq=new ArrayList<>();
        //s1: consecutive characters to store the length;

        for(int i=1;i<n;++i){

            if(word.charAt(i)==word.charAt(i-1)){

                ++cnt;
            } else{

                freq.add(cnt); //store the run length
                cnt=1;
            }
        }
        freq.add(cnt); //add the last counted segment

        long ans=1;
        for(int o:freq){


            ans = (ans * o) % mod;
        }
        //If the number of freq segments is s>=k, return ans directly

        if (freq.size() >= k) {
            return (int) ans;
        }

  // now we will make dp arr to count invalid arr

        int[] f=new int[k];
        int[] g=new int[k];

        f[0] = 1; //base case

        Arrays.fill(g, 1);
        for(int i = 0;i<freq.size();++i){

            int[] f_new=new int[k];
            for(int j=1;j<k;++j){

 //we will use prefix sums to calculate number of combinations
                f_new[j] = g[j - 1];
                if (j - freq.get(i) - 1 >= 0) {
                    f_new[j] = (f_new[j] - g[j - freq.get(i) - 1] + mod) % mod;
                }
            }

            //now we will update prefix sums 
            int[] g_new=new int[k];
            g_new[0] = f_new[0];
            for (int j = 1; j < k; ++j) {
                g_new[j] = (g_new[j - 1] + f_new[j]) % mod;
            }
            f = f_new;
            g = g_new;
        }

///now subtract invalid sequences from the total 

        return (int) ((ans - g[k - 1] + mod) % mod);
    }
}