/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

    private:
    #define vi vector<int>
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vi, greater<int>> q;
        for(int i=0;i<lists.size();i++){
            while(lists[i]){
                q.push(lists[i]->val);
                lists[i]=lists[i]->next;

            }
        }

      if(q.size()==0){
        return NULL;

      }


  ListNode* head=new ListNode(q.top());
  q.pop();
  ListNode* curr=head;

  while(q.size()>0){
  curr->next=new ListNode(q.top());
  q.pop();
  curr=curr->next;

  }


  return head;



    }
};