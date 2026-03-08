// Last updated: 08/03/2026, 13:23:50
class Solution {
    public char kthCharacter(int k) {
        int pos = k - 1;
        int count = 0;
        while(pos>0){
            count+=pos%2;
            pos/=2;
        }
        return(char)('a' + (count %26));
    }
}