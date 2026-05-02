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
    void findSpecialNodes(Node* node, int k, vector<Node*>& path, unordered_set<Node*>& specialNodes) {
        if (!node) return;

        path.push_back(node);


        if (!node->left && !node->right) {
            int pathSize = path.size();
      
            if (pathSize > k) {
                specialNodes.insert(path[pathSize - 1 - k]);
            }
        } else
        {
            //calling 
            if (node->left) findSpecialNodes(node->left, k, path, specialNodes);
            if (node->right) findSpecialNodes(node->right, k, path, specialNodes);
        }

        
        path.pop_back();
    }

    int kthFromLeaf(Node* root, int k) {
        if (!root) return 0;
        
        vector<Node*> path;
        unordered_set<Node*> specialNodes;
        findSpecialNodes(root, k, path, specialNodes);
        
        return specialNodes.size();
    }
};