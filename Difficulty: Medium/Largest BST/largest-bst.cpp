/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
   
    struct NodeInfo {
        bool isBST;
        int size;
        int minVal;
        int maxVal;
    };

public:
    NodeInfo solve(Node* root, int& maxSize) {
        if (!root) {
           
            return {true, 0, (int)2e5, (int)-2e5}; 
        }

        NodeInfo left = solve(root->left, maxSize);
        NodeInfo right = solve(root->right, maxSize);

     
        int currentSize = left.size + right.size + 1;

   
        if (left.isBST && right.isBST && 
            root->data > left.maxVal && root->data < right.minVal) {
            
            maxSize = max(maxSize, currentSize);
            
        
            return {true, currentSize, 
                    min(root->data, left.minVal), 
                    max(root->data, right.maxVal)};
        }

      
        return {false, currentSize, (int)-2e5, (int)2e5};
    }

    int largestBst(Node* root) {
        int maxSize = 0;
        solve(root, maxSize);
        return maxSize;
    }
};