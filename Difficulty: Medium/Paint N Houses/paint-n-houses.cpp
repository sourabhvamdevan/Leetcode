// User function Template for C++

class Solution {
  public:
    long long int distinctColoring(int N, int r[], int g[], int b[]) {
    
        long long int prev_red = r[0];
        long long int prev_green = g[0];
        long long int prev_blue = b[0];
        
        for (int i = 1; i < N; i++) {
         
            long long int curr_red = r[i] + min(prev_green, prev_blue);
            long long int curr_green = g[i] + min(prev_red, prev_blue);
            long long int curr_blue = b[i] + min(prev_red, prev_green);
            
   
            prev_red = curr_red;
            prev_green = curr_green;
            prev_blue = curr_blue;
        }
        
   
        return min({prev_red, prev_green, prev_blue});
    }
};