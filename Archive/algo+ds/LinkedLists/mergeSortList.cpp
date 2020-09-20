#include "LinkedList.h"

using namespace std;

node* findMidpoint(node* head){
  if(head == nullptr)
    return nullptr;

  node* mid = nullptr;
  node* slow = head;
  node* fast = head;

  while(fast->next != nullptr && fast->next->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

node* merge(node* a,node *b){
  // base cases
  if(a == nullptr && b == nullptr)
    return nullptr;
  if(a == nullptr && b != nullptr)
    return b;
  if(a != nullptr && b == nullptr)
    return a;

  // recursive cases
  node* head;
  if(a->data < b->data){
    head = a;
    a = a->next;
    head->next = merge(a,b);
  }
  else {
    head = b;
    b = b->next;
    head->next = merge(a,b);
  }

  return head;
}

void mergeSort(node* &head){
  // base case
  if(head == nullptr || head->next == nullptr)
    return;

  node* mid = findMidpoint(head);

  // Separate the list into two
  node* a = head;
  node* b = mid->next;
  mid->next = nullptr;

  // recursively sort both halves
  mergeSort(a);
  mergeSort(b);
  head = merge(a,b);
}

int main(){
  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  // mergesort the list
  mergeSort(head);
  // display the result
  display(head);
  cout<<"\n";

  return 0;
}
