/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:

    bool isIdentical(Node* r1, Node* r2)
    {
        if (!r1 && !r2) return true;
        if (!r1 || !r2) return false;
        
        return (r1->data == r2->data) && 
               isIdentical(r1->left, r2->left) && 
               isIdentical(r1->right, r2->right);
    }

    bool isSubTree(Node* root1, Node* root2) {
   
        if(!root2) return true;
        
   
        if(!root1) return false;


        if(isIdentical(root1, root2))
        
        {
            return true;
        }

    
        return isSubTree(root1->left, root2) || isSubTree(root1->right, root2);
    }
};