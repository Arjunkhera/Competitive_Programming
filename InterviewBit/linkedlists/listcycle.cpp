ListNode* removeLoop(ListNode *head,ListNode *fast){

  ListNode *slow = head;
  while(slow->next != fast->next){
      slow = slow->next;
      fast = fast->next;
  }
  if(slow == fast) return slow;
  else return slow->next;
}

ListNode* Solution::detectCycle(ListNode* head) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

  if(head == nullptr) return head;

  ListNode *slow = head,*fast = head;
  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast) break;
  }

  if(slow == fast) return removeLoop(head,fast);
  else return nullptr;
}
