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
    int countAllPaths(Node *root, int k) {
          unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;  
        return dfs(root, k, 0, prefixSum);
    }
    
private:
    int dfs(Node* node, int k, long long currentSum, unordered_map<int, int>& prefixSum) {
        if (!node) return 0;
        
        
        currentSum += node->data;
        

        int pathCount = prefixSum[currentSum - k];
        
   
        prefixSum[currentSum]++;
        
      
        pathCount += dfs(node->left, k, currentSum, prefixSum);
        pathCount += dfs(node->right, k, currentSum, prefixSum);
        

        prefixSum[currentSum]--;
        
        return pathCount;
        
    }
};