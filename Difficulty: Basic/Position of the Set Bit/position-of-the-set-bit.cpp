class Solution {
  public:
    int findPosition(int n) {
        // code here
        
        
         if (n == 0 || (n & (n - 1)) != 0)
        return -1;

    int pos = 1;
    int val = 1;
    while ((val & n) == 0)
    {
      
        val = val << 1;
        pos++;
    }
    return pos;
    }
};