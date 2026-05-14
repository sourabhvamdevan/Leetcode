/*Complete the function below
Node is as follows:
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
    struct Node* reverse(struct Node* head) {
        struct Node *prev = NULL, *curr = head, *next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    struct Node* modifyTheList(struct Node* head) {
        if (!head || !head->next) return head;

 
        struct Node *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        struct Node* head2 = reverse(slow->next);
        slow->next = NULL; 


        struct Node *curr1 = head, *curr2 = head2;
        while (curr1 && curr2) {
            int oldVal1 = curr1->data;
            curr1->data = curr2->data - curr1->data;
            curr2->data = oldVal1;
            
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

    
        slow->next = reverse(head2);

        return head;
    }
};