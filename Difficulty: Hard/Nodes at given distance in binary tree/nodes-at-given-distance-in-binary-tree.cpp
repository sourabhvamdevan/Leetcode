/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution {
public:

    Node* mapParents(Node* root, unordered_map<Node*, Node*>& parent_map, int target) {
        queue<Node*> q;
        q.push(root);
        Node* targetNode=nullptr;
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            if (current->data == target) targetNode = current;
            
            if (current->left) {
                parent_map[current->left]=current;
                q.push(current->left);
            }
            if (current->right) {
                parent_map[current->right] = current;
                q.push(current->right);
            }
        }
        return targetNode;
    }

    vector<int> KDistanceNodes(Node* root, int target, int k) {
        if (!root) return {};

        unordered_map<Node*, Node*> parent_map;
        Node* targetNode = mapParents(root, parent_map, target);
        

        if (!targetNode) return {};

  
        queue<Node*> q;
        q.push(targetNode);
        
        unordered_set<Node*> visited;
        visited.insert(targetNode);
        
        int current_dist = 0;
        
        while (!q.empty()) {
            if (current_dist == k) break;
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                
         
                if (curr->left && visited.find(curr->left) == visited.end()) {
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                
                
          
                if (curr->right && visited.find(curr->right) == visited.end()) {
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
          
                if (parent_map.count(curr) && visited.find(parent_map[curr]) == visited.end()) {
                    visited.insert(parent_map[curr]);
                    q.push(parent_map[curr]);
                }
                
                
                
            }
            current_dist++;
        }

     
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->data);
            q.pop();
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};