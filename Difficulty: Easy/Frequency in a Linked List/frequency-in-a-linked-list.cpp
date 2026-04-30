/*
  Node is defined as
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
}*head;
*/
class Solution {
  public:
    int count(struct Node* head, int key) {
        int frequency=0;
        Node* current=head;


        while (current != NULL){
     
            if (current->data == key) {
                frequency++;
            }
            
            
        
            current=current->next;
        }

        return frequency;
    }
};