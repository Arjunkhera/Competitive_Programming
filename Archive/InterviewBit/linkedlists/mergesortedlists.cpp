/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* a,ListNode* b){
  // base cases
  if(a == nullptr && b == nullptr) return nullptr;
  if(a == nullptr && b != nullptr) return b;
  if(a != nullptr && b == nullptr) return a;

  // recursive cases
  ListNode* head;
  if(a->val < b->val){
    head = a;
    a = a->next;
    head->next = mergeTwoLists(a,b);
  }
  else {
    head = b;
    b = b->next;
    head->next = mergeTwoLists(a,b);
  }

  return head;
}
