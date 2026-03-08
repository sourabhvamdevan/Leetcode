// Last updated: 08/03/2026, 13:22:37
class Solution {
    public int minDeletion(String s, int k) {
        int[] freq=new int[26];
        for (char c : s.toCharArray())freq[c - 'a']++;
        
        int sourabh=0;
        for (int f : freq) 
            if (f > 0) sourabh++;
        if(sourabh<=k)return 0;
        
        int[] chars=new int[sourabh];
        int idx=0;
        for(int i=0;i<26;i++) 
            if (freq[i] > 0) chars[idx++] = i;
        
        int minDel=s.length();
        for (int kanna=0; kanna<(1<<sourabh); kanna++){
            if (Integer.bitCount(kanna) <= k){

                
                int del = 0;
                for(int i = 0; i<sourabh; i++) if ((kanna & (1 << i)) == 0) del += freq[chars[i]];
                minDel = Math.min(minDel, del);
            }
        }


        
        return minDel;
    }
}