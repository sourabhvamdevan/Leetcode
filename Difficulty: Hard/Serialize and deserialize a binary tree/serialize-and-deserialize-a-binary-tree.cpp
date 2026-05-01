/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    vector<int> serialize(Node *root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr == NULL) {
                result.push_back(-1); 
            } else {
                result.push_back(curr->data);
                q.push(curr->left);
                q.push(curr->right);
            }
            
            
            
        }
        return result;
    }

  
    Node *deSerialize(vector<int> &arr){
        if (arr.empty() || arr[0] == -1) return NULL;

        Node* root=new Node(arr[0]);
        queue<Node*> q;
        q.push(root);

        int i=1;
        while (!q.empty() && i < arr.size()) {
            Node* curr = q.front();
            q.pop();

         
            if (arr[i] != -1) {
                curr->left = new Node(arr[i]);
                q.push(curr->left);
            }
            i++;


            if (i < arr.size() && arr[i] != -1) {
                curr->right = new Node(arr[i]);
                q.push(curr->right);
            }
            
            
            
            i++;
        }
        
        
        
        return root;
    }
};