class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        vector<int> res;
        int i=0,j=0,k=0;
        int n1 = a.size(), n2 = b.size(), n3 = c.size();

        while (i < n1 && j < n2 && k < n3) {
        
            if (a[i] == b[j] && b[j] == c[k]) {
                res.push_back(a[i]);
                int common = a[i];
                
            
                while (i < n1 && a[i] == common) i++;
                while (j < n2 && b[j] == common) j++;
                while (k < n3 && c[k] == common) k++;
            }
  
            else if (a[i] < b[j]) {
                i++;
            }
            else if (b[j] < c[k]) {
                j++;
            }
            else
            
            {
                k++;
    }
        }
        return res;
    }
};