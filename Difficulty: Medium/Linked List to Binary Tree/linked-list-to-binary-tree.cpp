/*
class NodeLL {
  public:
    int data;
    NodeLL *next;

    NodeLL(int x) {
        data = x;
        next = NULL;
    }
};
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node *linkedListToBinaryTree(NodeLL *head) {
        if (!head) return nullptr;

   
        Node *root=new Node(head->data);
        queue<Node*> q;
        q.push(root);

        head=head->next;

        while (head)
        
        {
      
            Node* parent=q.front();
            q.pop();

         
            Node* leftChild=new Node(head->data);
            parent->left=leftChild;
            q.push(leftChild);
            head=head->next;

       
            if (head)
            
            {
                Node* rightChild=new Node(head->data);
                parent->right=rightChild;
                q.push(rightChild);
                head=head->next;
            }
            
            
            
    }

        return root;
    }
};