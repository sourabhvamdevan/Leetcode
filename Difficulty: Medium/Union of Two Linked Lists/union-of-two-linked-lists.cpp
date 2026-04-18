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
    Node* makeUnion(Node* head1, Node* head2) {
    
        set<int> st;

    
        Node* curr=head1;
        while (curr != nullptr) {
            st.insert(curr->data);
            curr = curr->next;
        }

 
        curr = head2;
        while (curr != nullptr) {
            st.insert(curr->data);
            curr = curr->next;
        }

    
        Node* dummy= new Node(0);
        Node* res = dummy;

      
        for (auto it : st) {
            res->next = new Node(it);
            res = res->next;
        }

        
        Node* newHead = dummy->next;
        delete dummy; 
        
        return newHead;
    }
};