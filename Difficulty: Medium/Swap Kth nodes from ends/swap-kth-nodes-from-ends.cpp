/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        if(head==nullptr||head->next == nullptr) {
            return head;
        }
        
        int length=0;
        Node* temp=head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        
        if (k > length) {
            return head;
        }
        
        if (2 * k - 1 == length) {
            return head;
        }
        
        Node* beg_prev = nullptr;
        Node* beg = head;
        for (int i = 1; i < k; i++) {
            beg_prev = beg;
            beg = beg->next;
        }
        
        Node* end_prev = nullptr;
        Node* end = head;
        for (int i = 1; i < length - k + 1; i++) {
            end_prev = end;
            end = end->next;
        }
        
        if (beg_prev != nullptr) {
            beg_prev->next = end;
        } else {
            head = end;
        }
        
        if (end_prev != nullptr) {
            end_prev->next = beg;
        } else {
            head = beg;
        }
        
        Node* temp_next = beg->next;
        beg->next = end->next;
        end->next = temp_next;
        
        return head;
    }
};