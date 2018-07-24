/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* head){

  if(head == nullptr || head->next == nullptr) return;

    ListNode *prev,*temp,*cur,*slow = head,*fast = head;
    // find the midpoint
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse the second half of the list
    cur = slow->next; prev = nullptr; slow->next = nullptr;
    while(cur){
        temp = cur; cur = cur->next;
        temp->next = prev; prev = temp;
    }

    // merge the lists alternatively
    cur = head;
    while(prev){
        temp = cur->next;
        cur->next = prev;
        cur = temp;
        temp = prev->next;
        prev->next = cur;
        prev = temp;
    }
}
