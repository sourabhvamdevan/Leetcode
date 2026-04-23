#define ll long long

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        ll totalSum = 0;
        
 
        for (int num : arr) {
            totalSum += num;
        }

    
        if (totalSum % 2 != 0) {
            return false;
        }

        ll target = totalSum / 2;
        ll runningSum = 0;


        for (int num : arr) {
            runningSum += num;
            if (runningSum == target) {
                return true;
            }
       
            if (runningSum > target)
            {
                return false;
            }
        }

        return false;
    }
};