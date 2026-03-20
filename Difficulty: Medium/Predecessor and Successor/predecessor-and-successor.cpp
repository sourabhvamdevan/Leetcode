/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = nullptr;
        Node* suc = nullptr;
        Node* curr = root;

        while (curr != nullptr) {
           
            if (curr->data == key) {
              
                if (curr->left) {
                    Node* temp = curr->left;
                    while (temp->right) temp = temp->right;
                    pre = temp;
                }
               
                if (curr->right) {
                    Node* temp = curr->right;
                    while (temp->left) temp = temp->left;
                    suc = temp;
                }
                break; 
            } 
           
            else if (curr->data < key) {
               
                pre = curr;
                curr = curr->right;
            } 
         
            else {
               
                suc = curr;
                curr = curr->left;
            }
        }

      
        return {pre, suc};
    }
};