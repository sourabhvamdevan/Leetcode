/*
Structure of the node of Huffman tree is as
struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;
};
*/

class Solution {
public:
    string decodeHuffmanData(struct MinHeapNode* root, string binaryString) {
        string decodedString = "";
        
  
        if(!root) return "";
        if (binaryString.empty()) {
        
            if (!root->left and !root->right) return string(1, root->data);
            return "";
        }

        struct MinHeapNode* curr=root;

        for (int i=0;i<binaryString.length();i++)
        
        {
   
            if (binaryString[i] == '0') {
                if(curr->left) curr=curr->left;
            } else
            
            {
                if (curr->right) curr = curr->right;
            }

     
            if (!curr->left && !curr->right) {
                decodedString += curr->data;
                curr = root; 
            }
            
            
            
        }

        return decodedString;
    }
};