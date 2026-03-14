/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
            if (root ==  nullptr) {
        return {};
    }
    Node *temp = nullptr;
  
    
    queue<pair<Node *, int>> q;
  
  
    unordered_map<int, int> mp;

    int mn = INT_MAX;
    q.push({root, 0});
    while (!q.empty()){
      
        temp = q.front().first;
        int d = q.front().second;
        mn = min(mn, d);
        q.pop();
      
        
        if (mp.find(d) == mp.end()) {
            mp[d] = temp->data;
        }
      
        if (temp->left) {
            q.push({temp->left, d - 1});
        }
      
   
        if (temp->right) {
            q.push({temp->right, d + 1});
        }
    }
    vector<int> ans(mp.size());
  

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans[it->first - mn] = (it->second);
}
  
    return ans;
    }
};