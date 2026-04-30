/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false



class Solution {
  public:
   
    int checkSum(Node* root) {
   
        if (root==NULL) return 0;

 
        if (root->left==NULL && root->right == NULL) return root->data;


        int leftSum=checkSum(root->left);
        int rightSum=checkSum(root->right);


        if(leftSum == -1 || rightSum == -1) return -1;

 
        if (root->data == leftSum + rightSum) {
    
            return root->data + leftSum + rightSum;
        }
        
        


        return -1;
    }

    bool isSumTree(Node* root)
    
    {

        return checkSum(root) != -1;
    }
};