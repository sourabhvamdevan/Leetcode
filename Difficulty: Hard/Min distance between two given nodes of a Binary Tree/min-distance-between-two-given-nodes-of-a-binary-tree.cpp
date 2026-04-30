/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
 
    Node* findLCA(Node* root, int a, int b) {
        if (!root || root->data == a || root->data == b)
            return root;

        Node* leftLCA=findLCA(root->left, a, b);
        Node* rightLCA=findLCA(root->right, a, b);

        if (leftLCA && rightLCA) return root;
        return (leftLCA != NULL) ? leftLCA : rightLCA;
    }


    int findLevel(Node* root, int val, int level)
    
    {
    if (!root) return -1;
    if (root->data == val) return level;

        int left = findLevel(root->left, val, level + 1);
        if (left != -1) return left;

        return findLevel(root->right, val, level + 1);
    }

    int findDist(Node* root, int a, int b)
    
    {
     
        Node* lca = findLCA(root, a, b);

      
        int d1=findLevel(lca, a, 0);
        
    
        int d2=findLevel(lca, b, 0);

        return d1+d2;
    }
};