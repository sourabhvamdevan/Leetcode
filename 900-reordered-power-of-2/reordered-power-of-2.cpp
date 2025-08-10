class Solution {
    private:
    #define vi vector<int>
public:

vi Helper(long n){
    vi num(10);
    while(n){
        num[n%10]++;
        n=n/10;

    } 

    return num;

}
    bool reorderedPowerOf2(int n) {
        vi v=Helper(n);
        for(int i=0;i<31;i++){
            if(v==Helper(1<<i)){
                return true;

            }
        }



        return false;
    }

    
};