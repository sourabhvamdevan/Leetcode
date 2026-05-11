/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */



class Solution {
  public:
    int solve(Node* root, int &max_diff)
    
    {
  
        if(!root)return 1e9; 
        
   
        if (!root->left and !root->right) return root->data;

 
        int leftMin=solve(root->left, max_diff);
        int rightMin=solve(root->right, max_diff);

        int subtreeMin=min(leftMin, rightMin);


        max_diff=max(max_diff, root->data - subtreeMin);

      
        return min(root->data, subtreeMin);
    }

    int maxDiff(Node* root)
    
    {
        int max_diff=INT_MIN;
        solve(root, max_diff);
        return max_diff;
    }
};