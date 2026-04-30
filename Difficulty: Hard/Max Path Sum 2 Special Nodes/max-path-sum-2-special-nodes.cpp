/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int solve(Node* root, int &maxi) {
        if (!root) return 0;
        
  
        if (!root->left && !root->right)
        {
            return root->data;
        }


        int leftSum=(root->left) ? solve(root->left, maxi) : -1e9;
        int rightSum=(root->right) ? solve(root->right, maxi) : -1e9;


        if (root->left && root->right) {
            maxi=max(maxi, leftSum + rightSum + root->data);
            return max(leftSum, rightSum) + root->data;
        }

  
        return (root->left ? leftSum : rightSum) + root->data;
    }

    int maxPathSum(Node* root) {
        int maxi=INT_MIN;
        int val=solve(root, maxi);
        
        if (maxi==INT_MIN) return val;
        
        return maxi;
    }
};