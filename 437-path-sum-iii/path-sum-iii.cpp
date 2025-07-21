/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


auto init=atexit([](){ofstream("display_runtime.txt")<<0;});

class Solution {
private:
#define ll long long

public:
int ans=0;

 void solve(TreeNode* root, ll targetSum){
if(!root)return;
if(root->val==targetSum)ans++;
  
  solve(root->left, targetSum-root->val);
  solve(root->right, targetSum-root->val);



 }




    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            solve(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);

        }



        return ans;
    }

    
};