/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        Queue<TreeNode> q=new LinkedList<>();
        Queue<Integer> qi=new LinkedList<>();
        if(root==null) return 0;
        q.add(root);
        qi.add(1);
        int max=0;
        while(!q.isEmpty()){
            int end=0;
            int start=0;
            int n=q.size();
            
            for(int i=0;i<n;i++){
                TreeNode curr=q.poll();
                int a=qi.poll(); //index
                
                if(i==start) start=a;
                if(i==n-1) end=a;
                if(curr.left!=null){
                    q.add(curr.left);
                    qi.add(2*a);
                }
                if(curr.right!=null){
                    q.add(curr.right);
                    qi.add(2*a+1);
                }
            }
            max=Math.max(max,end-start+1);
        }
        return max;
    }
}