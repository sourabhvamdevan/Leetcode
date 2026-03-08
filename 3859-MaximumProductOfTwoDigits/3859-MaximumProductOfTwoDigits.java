// Last updated: 08/03/2026, 13:22:40
class Solution {
    public int maxProduct(int n) {

        String sourabh=String.valueOf(n);

        int maxProduct=0;
        for(int i=0;i<sourabh.length();i++){
            for(int j=0;j<sourabh.length();j++){
                if(i==j)continue;
                int digit1=sourabh.charAt(i)-'0';
                int digit2=sourabh.charAt(j)-'0';

                maxProduct=Math.max(maxProduct,digit1*digit2);

                
            }
        }

        return maxProduct;

        
    }
}