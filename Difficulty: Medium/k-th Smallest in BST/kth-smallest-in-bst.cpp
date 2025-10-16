/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Helper function for inorder traversal
    void inorder(Node* root, int& k, int& ans) {
        if (root == nullptr)
            return;

        inorder(root->left, k, ans);
        
        k--; // Decrease k for each node visited
        if (k == 0) {
            ans = root->data;
            return;
        }

        inorder(root->right, k, ans);
    }

    int kthSmallest(Node *root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};
