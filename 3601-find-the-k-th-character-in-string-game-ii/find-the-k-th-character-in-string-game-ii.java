class Solution {
    public char kthCharacter(long k, int[] arr
    ) {
        int cnt=0;
        for(int i=arr.length; i>=0; i--)
         if(k>Math.pow(2,i)){
            k-=Math.pow(2,i);
            if(arr[i]==1) cnt++;

         }

         cnt %=26;
         return (char) ('a'+cnt);
    }
}