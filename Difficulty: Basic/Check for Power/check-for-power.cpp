class Solution {
  public:
    bool isPower(int x, int y) {
        // code here
        if (x == 1)
        return y == 1;

   
    if (y == 1)
        return true;

    
    double res = log(y) / log(x);
    
   
    return fabs(res - round(res)) < 1e-10;
    }
};