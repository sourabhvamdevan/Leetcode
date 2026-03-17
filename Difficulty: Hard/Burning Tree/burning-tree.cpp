/*
class Node {
  public:
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
    int minTime(Node* root, int target) {
        if (!root) return 0;
        
        
        unordered_map<Node*, Node*> parentMap;
        Node* targetNode = createParentMapAndFindTarget(root, target, parentMap);
        
        
        return burnTree(targetNode, parentMap);
    }
    
private:
    Node* createParentMapAndFindTarget(Node* root, int target, 
                                       unordered_map<Node*, Node*>& parentMap) {
        queue<Node*> q;
        q.push(root);
        Node* targetNode = nullptr;
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            if (current->data == target) {
                targetNode = current;
            }
            
            if (current->left) {
                parentMap[current->left] = current;
                q.push(current->left);
            }
            
            if (current->right)
            {
                parentMap[current->right] = current;
                q.push(current->right);
    }
        }
        
        return targetNode;
    }
    
    int burnTree(Node* targetNode, unordered_map<Node*, Node*>& parentMap) {
        if (!targetNode) return 0;
        
        queue<Node*> q;
        unordered_map<Node*, bool> visited;
        int time = 0;
        
        q.push(targetNode);
        visited[targetNode] = true;
        
        while (!q.empty()) {
            int size = q.size();
            bool fireSpread = false;
            
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                
            
                if (current->left && !visited[current->left]) {
                    visited[current->left] = true;
                    q.push(current->left);
                    fireSpread = true;
                }
                
                
                if (current->right && !visited[current->right]) {
                    visited[current->right] = true;
                    q.push(current->right);
                    fireSpread = true;
                }
                
                
                if (parentMap.count(current) and !visited[parentMap[current]])
                {
                    visited[parentMap[current]] = true;
                    q.push(parentMap[current]);
                    fireSpread = true;
    }
            }
            
            if (fireSpread) {
                time++;
            }
        }
        
        return time;
    }
};