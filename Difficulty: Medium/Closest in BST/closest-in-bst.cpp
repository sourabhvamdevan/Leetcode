/*
Tree Node
struct Node {
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
    int minDiff(Node *root, int K) {
        int min_diff=INT_MAX;
        Node *current=root;

        while(current!=NULL){
        
            int current_diff=abs(current->data - K);
            if (current_diff<min_diff) {
                min_diff=current_diff;
            }

      
            if (current_diff == 0) {
                return 0;
            }

         
            if (K < current->data) {
                current = current->left;
            } else {
                current=current->right;
            }
            
            
            
        }

        return min_diff;
    }
};