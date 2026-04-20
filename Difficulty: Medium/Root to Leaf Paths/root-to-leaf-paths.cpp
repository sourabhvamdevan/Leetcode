/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void findPaths(Node* node, vector<int>& currentPath, vector<vector<int>>& result) {
        if (!node) return;

 
        currentPath.push_back(node->data);

     
        if (!node->left && !node->right) {
            result.push_back(currentPath);
        } else {
         
            if (node->left) findPaths(node->left, currentPath, result);
            if (node->right) findPaths(node->right, currentPath, result);
        }

    
        currentPath.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> currentPath;
        
        if (root) {
            findPaths(root, currentPath, result);
        }
        
        return result;
    }
};