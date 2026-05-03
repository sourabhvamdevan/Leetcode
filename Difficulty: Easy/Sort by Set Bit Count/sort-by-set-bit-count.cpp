class Solution {
public:

    int countSetBits(int n) {
        int cnt = 0;
        while (n > 0){
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }

    vector<int> sortBySetBitCount(vector<int>& arr) {

        stable_sort(arr.begin(), arr.end(), [this](int a, int b) {
            return countSetBits(a) > countSetBits(b);
        });
        
        return arr; 
    }
};