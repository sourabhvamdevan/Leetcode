/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:

    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addOne(Node* head) {
     
        head = reverseList(head);
        
        Node* curr = head;
        int carry = 1; 
        
        Node* prev = NULL;
        while (curr != NULL && carry > 0) {
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;
            
            prev = curr;
            curr = curr->next;
        }
        
   
        if (carry > 0) {
            prev->next = new Node(carry);
        }
        
        
        return reverseList(head);
    }
};