/*
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
        next = NULL;
    }
};
*/

class Solution {
  public:
 
    Node* reverseList(Node* head) {
        Node *prev = NULL, *curr = head, *next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }


    Node* merge(Node* l1, Node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        Node* dummy = new Node(-1);
        Node* curr = dummy;

        while (l1 && l2) {
            if (l1->data <= l2->data) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1) curr->next = l1;
        else curr->next = l2;

        return dummy->next;
    }

    Node* sort(Node* head) {
        if (!head || !head->next) return head;


        Node* ascHead = head;
        Node* descHead = head->next;
        
        Node* p1 = ascHead;
        Node* p2 = descHead;

        while (p1 && p2) {
            p1->next = p2->next;
            p1 = p1->next;
            if (p1) {
                p2->next = p1->next;
                p2 = p2->next;
            }
        }

    
        descHead = reverseList(descHead);


        return merge(ascHead, descHead);
    }
};