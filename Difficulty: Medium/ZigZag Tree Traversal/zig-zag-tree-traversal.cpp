/*
Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);
        
   
        bool leftToRight=true;

        while (!q.empty()){
            int size=q.size();
            vector<int> level(size);

            for(int i=0;i<size;i++){
                Node* curr=q.front();
                q.pop();

        
                int index=leftToRight ? i : (size - 1 - i);
                level[index]=curr->data;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

   
            leftToRight=!leftToRight;


            for (int val : level){
                result.push_back(val);
            }
            
            
            
        }

        return result;
    }
};