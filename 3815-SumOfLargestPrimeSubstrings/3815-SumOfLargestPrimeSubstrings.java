// Last updated: 08/03/2026, 13:22:57


class Solution {
    public long sumOfLargestPrimes(String s){
        List<Long> primes=new ArrayList<>();
        int n=s.length();
        for(int i = 0;i<n;i++)
        {
            for(int j = i;j<n;j++)
            {
                String substr=s.substring(i,j+1);
                long num=Long.parseLong(substr);
                if(num>1 && ifPrimes(num)) {
                    primes.add(num);
                }

                
            }

            
        }
        primes.sort(Comparator.reverseOrder());
        long sums=0;
        int cnt=0;
        Long prev=null;
        for(long prime:primes){

            
            if(prev==null||prime!=prev){
                sums+=prime;
                prev=prime;
                cnt++;
                if(cnt == 3)break;

                
            }
        }

        
        return sums;
    }

    private boolean ifPrimes(long n){
        if(n <= 1)return false;
        if(n == 2)return true;
        if(n % 2 == 0)return false;
        for(long i=3;i*i<=n;i+=2){
            if(n%i==0)return false;
        }

        
        return true;
    }
}