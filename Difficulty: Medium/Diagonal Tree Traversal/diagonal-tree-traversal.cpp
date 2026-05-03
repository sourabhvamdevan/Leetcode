/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int> res;
        if (!root) return res;


        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

       
            while (curr) {
           
                res.push_back(curr->data);

             
                if (curr->left) {
                    q.push(curr->left);
                }

             
                curr=curr->right;
            }
        }

        return res;
    }
};