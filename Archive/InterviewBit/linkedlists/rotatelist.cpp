/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* head, int k){

      if(head == nullptr || head->next == nullptr) return head;

      int stop,length = 0;
      ListNode *temp,*newHead,*cur = head;
      while(cur){ length++; cur = cur->next; }

      k = k%length;
      if(!k) return head;

      stop = length-k-1;
      cur = head;
      while(stop){
          cur = cur->next;
          stop--;
      }

      newHead =  cur->next;
      cur->next = nullptr;
      cur = newHead;
      while(cur->next) cur = cur->next;
      cur->next = head;
      return newHead;

}
