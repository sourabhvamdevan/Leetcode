// Last updated: 08/03/2026, 13:23:19
class Solution {
    public String answerString(String s, int fr) {

        //if no characters r removed then 
        if(fr==1)return s;


        int n=s.length(); //len of the input string
        String max = ""; //yeh lexicographically max string store krega 


        for(int j=0;j<n;j++)
        {
            int remain=fr-1-j; //remaining character to remove after index j
            String s2 = "";
            if(remain>0)
                 s2=s.substring(j,n-remain);
            else
                 s2 = s.substring( j , n );
            if( s2.compareTo(max) > 0 )
                max = s2;
        }



        return max;
    }
}