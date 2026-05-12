class Solution {
  public:
    int maxSubstring(string s) {
        int n = s.size();
        int max_so_far=-1; 
        int current_max=0;
        bool hasZero=false;

        for(int i=0;i<n;i++){
            
            int val=(s[i] == '0') ? 1 : -1;
            
            if(val==1) hasZero = true;

            current_max += val;

            if (current_max > max_so_far) {
                max_so_far = current_max;
            }

        
            if (current_max < 0)
            
            {
                current_max = 0;
            }
        }

     
        return hasZero ? max_so_far : -1;
    }
};