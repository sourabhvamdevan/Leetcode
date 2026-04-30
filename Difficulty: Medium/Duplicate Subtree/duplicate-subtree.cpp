/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
   
    string solve(Node* root, unordered_map<string, int>& m, bool& found) {
   
        if(!root)return "$";

  
        string s="";
        
  
    if(!root->left && !root->right){
            s = to_string(root->data);
            return s;
        }

   
        s += to_string(root->data);
        s += "," + solve(root->left, m, found);
        s += "," + solve(root->right, m, found);


        if (found) return s;

 
        if (m.find(s)!=m.end()) {
            found = true;
        } else
        
        {
            m[s]++;
        }

        return s;
    }

    int dupSub(Node *root) {
        unordered_map<string, int> m;
        bool found = false;
        solve(root, m, found);
        return found ? 1 : 0;
    }
};