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
    vector<int> bottomView(Node *root) {
        vector<int> res;
        if (root == nullptr) return res;

    
        map<int, int> hd_map;
        
 
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* curr = temp.first;
            int hd = temp.second;
            
        
            hd_map[hd] = curr->data;
            
            if (curr->left) {
                q.push({curr->left, hd - 1});
            }
            if (curr->right) {
                q.push({curr->right, hd + 1});
            }
        }
        

        for (auto const& [hd, val] : hd_map) {
            res.push_back(val);
        }
        
        return res;
    }
};