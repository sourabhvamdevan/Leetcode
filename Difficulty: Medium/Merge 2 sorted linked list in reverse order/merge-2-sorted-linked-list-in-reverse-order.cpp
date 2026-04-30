/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/


class Solution {
  public:
    struct Node *mergeResult(Node *node1, Node *node2) {
        Node *result = NULL;
        Node *temp = NULL;


        while (node1 != NULL && node2 != NULL) {
            if (node1->data <= node2->data) {
   
                temp = node1->next;
                node1->next = result;
                result = node1;
                node1 = temp;
            } else
            
            {
         
                temp = node2->next;
                node2->next = result;
                result = node2;
                node2 = temp;
            }
            
            
            
        }

  
        while (node1 != NULL){
            temp = node1->next;
            node1->next = result;
            result = node1;
            node1 = temp;
        }
        
        

   
        while (node2 != NULL){
            temp = node2->next;
            node2->next = result;
            result = node2;
            node2 = temp;
        }

        return result;
    }
};