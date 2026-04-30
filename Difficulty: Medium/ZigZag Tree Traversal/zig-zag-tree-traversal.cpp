/*
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

    vector<int> zigZagTraversal(Node* root)
    {
        vector<int> result;
        if(!root) return result;

        queue<Node*> q;
        q.push(root);
        
    
        bool leftToRight = true;

        while(!q.empty()){
            int size=q.size();
            vector<int> row(size);

            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();

       
                int index=leftToRight ? i : (size - 1 - i);
                row[index]=node->data;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

         
            leftToRight = !leftToRight;
            
      
            for (int val : row) {
                result.push_back(val);
            }
            
            
            
            
        }

        return result;
    }
};