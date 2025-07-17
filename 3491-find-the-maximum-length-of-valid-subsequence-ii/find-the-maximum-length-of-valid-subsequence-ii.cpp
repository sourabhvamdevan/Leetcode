class Solution {

    private:
    #define vi vector<int>
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans=1;
        for(int r=0;r<k;r++){
            vi freq(k,0);
            for(int x:nums){
                int t=x%k;
                int prev=(r-t+k)%k;
                freq[t]=freq[prev]+1;
                ans=max(ans,freq[t]);
            }
        }


        return ans;
    }
};