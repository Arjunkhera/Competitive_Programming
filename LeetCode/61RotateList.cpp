// just change struct name to ListNode, rest of the function is same
// the remainder of functions are to create a linked list

#include<iostream>

using namespace std;

struct node{
  int data;
  node* next;
  node(int dat):data(dat),next(nullptr){}
};

void insertAtHead(node* &head,int data){
  node* newNode = new node(data);
  newNode->next = head;
  head = newNode;
}

void readList(node* &head){
  int x;
  std::cin>>x;

  while(x!=-1){
    insertAtHead(head,x);
    std::cin>>x;
  }
}

void display(node* head){
  while(head != nullptr){
    std::cout<<head->data<<" ";
    head = head->next;
  }
}

node* removeNthFromEnd(node* head, int n){

  node* prev = head;
  node* fast = head;
  while(n && fast->next != nullptr){
    n--;
    fast = fast->next;
  }

  while(fast->next != nullptr){
    prev = prev->next;
    fast = fast->next;
  }

  return prev;
}

node* rotateRight(node* head, int k){
  // zero length list
  if(head == nullptr)
    return nullptr;

  node* tail = head;
  int length = 1;

  while(tail->next != nullptr){
    length++;
    tail = tail->next;
  }

  k = k%length;
  if(k == 0)
    return head;

  node* prev = removeNthFromEnd(head,k);
  node* newHead = prev->next;
  prev->next = nullptr;
  tail->next = head;
  head = newHead;

  return head;
}

int main(){

  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  head = rotateRight(head,1);
  display(head);
  cout<<"\n";

  return 0;
}

// can be also done w/o the above function, just move len-k position from tail after forming a loop
// a discussion solution
/*ListNode* rotateRight(ListNode* head, int k) {
      if(!head) return head;

      int len=1; // number of nodes
      ListNode *newH, *tail;
      newH=tail=head;

      while(tail->next)  // get the number of nodes in the list
      {
          tail = tail->next;
          len++;
      }
      tail->next = head; // circle the link

      if(k %= len)
      {
          for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
      }
      newH = tail->next;
      tail->next = NULL;
      return newH;
  }
*/
