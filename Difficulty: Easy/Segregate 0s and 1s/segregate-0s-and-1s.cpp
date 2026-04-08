class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;

        while (left < right){
        
            while (arr[left] == 0 && left < right) {
                left++;
            }

         
            while (arr[right] == 1 && left < right){
                right--;
            }

            
            if (left < right){
                arr[left] = 0;
                arr[right] = 1;
                left++;
                right--;
    }
        }
    }
};