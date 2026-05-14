/*Link list node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/



class Solution {
  public:
    Node* insertionSort(struct Node* head) {
      
        if (!head || !head->next) {
            return head;
        }

        Node* sorted = nullptr; 
        Node* curr = head;      

        while (curr != nullptr) {
   
            Node* next = curr->next;

     
            sorted = sortedInsert(sorted, curr);


            curr = next;
        }

        return sorted;
    }

  private:

    Node* sortedInsert(Node* sorted_head, Node* new_node) {
 
        if (sorted_head == nullptr || sorted_head->data >= new_node->data) {
            new_node->next = sorted_head;
            return new_node;
        }

 
        Node* curr = sorted_head;
        while (curr->next != nullptr && curr->next->data < new_node->data) {
            curr = curr->next;
        }

        new_node->next = curr->next;
        curr->next = new_node;

        return sorted_head;
    }
};