// Last updated: 08/03/2026, 13:23:20
class Solution {
    int mod=(int)(1e9+7);
    public int countGoodArrays(int n, int m, int k) {

        //f[i] stores factorial of i modulo mod
        long[]f=new long[n+1];
        f[0]=1;
        f[1]=1;
        //precompute factorial upto n
        for(int i=2;i<f.length;i++){
            f[i]=(f[i-1]*i%mod);
        }

//comb(n-1,k)=ways to choose positions where increases happen 
///k will peak in n-1 position
          long ans=comb(n-1,k,f);
          ans=ans*m%mod;
          ans=ans*ex(m-1,n-k-1)%mod;
          return (int)ans;
     
    }



    public long ex(long b,long e){
          long ans=1;
          while(e>0){
            if(e%2==1){
                ans=(ans*b)%mod;
            }


            b=(b*b)%mod;
            e=e>>1;
          }


          return ans;
    }

    //yeh compute krega nCr % mod using precomputed factorials.
    
    public long comb(int n,int r,long[]f){

        // comb(n, r) = n! / (r! * (n-r)!) % mod
        return f[n]*(ff(f[r]))%mod*ff(f[n-r])%mod;
    }

//compute modular inverse using fermat little theorum 
///ff(x)=x^(mod-2)%mod;

    public long ff(long x){
        return ex(x,mod-2);
    }


    
}