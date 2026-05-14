//Back-end complete function Template for C++

class Solution {
    int postIndex;

public:
    bool solve(int preorder[], int inorder[], int postorder[], int inStart, int inEnd, int& preIndex, int N) {
        if (inStart > inEnd) return true;

       
        int rootVal = preorder[preIndex++];
        
      
        int inIndex=-1;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                inIndex = i;
                break;
            }
            
            
        }

    
        if (inIndex == -1) return false;

  
        if (!solve(preorder, inorder, postorder, inStart, inIndex - 1, preIndex, N))
            return false;

 
        if (!solve(preorder, inorder, postorder, inIndex + 1, inEnd, preIndex, N))
            return false;

       
        if (postIndex >= N || rootVal != postorder[postIndex++])
            return false;

        return true;
    }

    bool checktree(int preorder[], int inorder[], int postorder[], int N) {
        int preIndex=0;
        postIndex=0;
        
      
        bool result=solve(preorder, inorder, postorder, 0, N - 1, preIndex, N);
        
   
        return result && (postIndex == N);
    }
};