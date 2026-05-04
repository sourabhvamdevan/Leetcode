class Solution {
  public:
    int isPallindrome(long long int N) {
    
        long long int rev = 0;
        long long int temp = N;

        while (temp > 0)
        {
       
            rev = (rev << 1) | (temp & 1);
         
            temp >>= 1;
        }


        return (N == rev) ? 1 : 0;
    }
};