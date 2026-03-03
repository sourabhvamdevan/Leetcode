/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    Node* lca(Node* root, int n1, int n2) {
        
        if (!root) 
            return nullptr;

   
        if (root->data == n1 || root->data == n2)
            return root;

        Node* leftLca = lca(root->left, n1, n2);
        Node* rightLca = lca(root->right, n1, n2);

        if (leftLca && rightLca)
            return root;

        return leftLca ? leftLca : rightLca;
    }
};