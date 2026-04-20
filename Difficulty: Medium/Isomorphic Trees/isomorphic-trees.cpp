/*Complete the function below
Node is as follows:
struct Node {
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
    bool isIsomorphic(Node *root1, Node *root2) {
     
        if (root1 == NULL && root2 == NULL) return true;

     
        if (root1 == NULL || root2 == NULL) return false;
        if (root1->data != root2->data) return false;

       
        bool notSwapped = isIsomorphic(root1->left, root2->left) && 
                          isIsomorphic(root1->right, root2->right);
        
       
        bool swapped = isIsomorphic(root1->left, root2->right) && 
                       isIsomorphic(root1->right, root2->left);

        return notSwapped||swapped;
    }
};