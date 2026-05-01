/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:

    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }


    bool isCBT(Node* root, int index, int totalNodes) {
        if (!root) return true;
        
   
        if (index >= totalNodes) return false;

        return isCBT(root->left, 2*index+1, totalNodes) && 
               isCBT(root->right, 2*index+2, totalNodes);
    }


    bool isMaxOrder(Node* root)
    {

        if (!root->left && !root->right) return true;

  
        if (!root->right) {
            return root->data >= root->left->data;
        }

 
        if (root->data >= root->left->data && root->data >= root->right->data) {
            return isMaxOrder(root->left) && isMaxOrder(root->right);
        }
        
        return false;
    }

    bool isHeap(Node* tree) {
        if (!tree) return true;

        int totalNodes=countNodes(tree);
        
    
        if (isCBT(tree, 0, totalNodes) && isMaxOrder(tree)) {
            return true;
        }
        
        
        
        
        return false;
    }
};