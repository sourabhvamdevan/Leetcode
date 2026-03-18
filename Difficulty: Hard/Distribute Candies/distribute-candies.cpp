/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    int moves = 0;

 
    int traverse(Node* root) {
        if (!root) return 0;

        
        int left_balance = traverse(root->left);
        int right_balance = traverse(root->right);

     
        moves += abs(left_balance) + abs(right_balance);

      
        return root->data + left_balance + right_balance - 1;
    }

    int distCandy(Node* root) {
        moves = 0;
        traverse(root);
        return moves;
    }
};