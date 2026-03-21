// User function template for C++

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
    Node* divide(Node* head) {
        if (!head || !head->next) return head;

        Node* evenHead = new Node(0);
        Node* oddHead = new Node(0);
        
     
        Node* evenTail = evenHead;
        Node* oddTail = oddHead;
        
        Node* curr = head;
        
        while (curr != nullptr) {
            if (curr->data % 2 == 0) {
           
                evenTail->next = curr;
                evenTail = evenTail->next;
            } else {
            
                oddTail->next = curr;
                oddTail = oddTail->next;
            }
            curr = curr->next;
        }
        

        evenTail->next = oddHead->next;
        
    
        oddTail->next = nullptr;
        
       
        Node* newHead = evenHead->next;
        
      
        delete evenHead;
        delete oddHead;
        
        return newHead;
    }
};