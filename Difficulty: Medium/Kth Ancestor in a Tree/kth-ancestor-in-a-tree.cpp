/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
public:
    int result = -1;

    int solve(Node* root, int &k, int target) {
        if (!root) return -1;

 
        if(root->data==target)return 0;

   
        int left=solve(root->left, k, target);
        int right=solve(root->right, k, target);

  
        if (left != -1||right != -1) {
        
            int dist = (left != -1) ? left : right;
            
           
            if (dist + 1 == k) {
                result = root->data;
            }
            
         
            return dist + 1;
        }

        return -1;
    }

    int kthAncestor(Node *root, int k, int node) {
        result = -1; 
        solve(root, k, node);
        return result;
    }
};