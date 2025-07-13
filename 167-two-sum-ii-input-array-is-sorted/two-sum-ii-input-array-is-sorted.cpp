class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int l=0;
        int r=num.size()-1;
        while(l<r){
            if(num[l]+num[r]==target){
                return {l+1,r+1};

            } else if(num[l]+num[r]>target){
                r--;

            }else {
                l++;

            }
        }

        return {};
    }
};