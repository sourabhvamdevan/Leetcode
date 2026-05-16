// User function Template for C++

class Solution {
public:
    void flatten(Node *root) {
        Node* current = root;
        
        while (current != nullptr)
        
        {
            if (current->left != nullptr) {
            
                Node* predecessor = current->left;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
                
             
                predecessor->right = current->right;
                
              
                current->right = current->left;
                current->left = nullptr;
            }
       
            current = current->right;
        }
    }
};