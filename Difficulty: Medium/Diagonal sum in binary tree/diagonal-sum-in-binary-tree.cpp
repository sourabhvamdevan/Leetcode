/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/

class Solution {
  public:
    vector<int> diagonalSum(Node* root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            int currentDiagonalSum=0;

     
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

          
                while (curr){
                    currentDiagonalSum+=curr->data;

                
                    if (curr->left) {
                        q.push(curr->left);
                    }

               
                    curr=curr->right;
                }
                
                
                
            }
            result.push_back(currentDiagonalSum);
        }

        return result;
    }
};