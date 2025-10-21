/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/



class Solution {
  public:
    void inorder(Node* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->data);
        inorder(root->right, vals);
    }

    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> vals;
        inorder(root, vals);  

 
        sort(vals.begin(), vals.end(), [&](int a, int b) {
            int diffA = abs(a - target);
            int diffB = abs(b - target);
            if (diffA == diffB) return a < b;  
            return diffA < diffB;              
        });

      
        vector<int> result;
        for (int i = 0; i < k && i < vals.size(); i++)
            result.push_back(vals[i]);

        return result;
    }
};
