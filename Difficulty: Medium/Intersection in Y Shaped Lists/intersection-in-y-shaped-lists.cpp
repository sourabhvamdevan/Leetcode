/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        if (!head1 || !head2) return nullptr;

        Node* ptr1 = head1;
        Node* ptr2 = head2;

        
        while (ptr1 != ptr2) {
            
            ptr1 = (ptr1 == nullptr) ? head2 : ptr1->next;
            
            
            ptr2 = (ptr2 == nullptr) ? head1 : ptr2->next;
        }

        
        return ptr1;
    }
};