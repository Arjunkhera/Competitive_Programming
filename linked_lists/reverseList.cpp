#include "LinkedList.h"

using namespace std;

node* reverseListRecursive(node* &head){
  // we have reached the last element of the original list
  if(head->next == nullptr)
    return head;

  // temp is the last element of our already traversed list
  node* temp = head;
  // we make head to point to the remaining list to be reversed
  head = head->next;
  // obtain the tail of the reversed linked list
  node* tail = reverseListRecursive(head);
  // add the element temp to the tail of the list
  tail->next = temp;
  temp->next = nullptr;
  // return the tail of the reversed list
  return temp;
}

void reverseListIterative(node* &head){
  node* temp = nullptr;
  node* prev = nullptr;
  while(head != nullptr){
    temp = head->next;
    head->next = prev;
    prev = head;
    head = temp;
  }
  head = prev;
}

int main(){
  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  reverseListRecursive(head);
  display(head);
  cout<<"\n";

  reverseListIterative(head);
  display(head);
  cout<<"\n";

  return 0;
}
