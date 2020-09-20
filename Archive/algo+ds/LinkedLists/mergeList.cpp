#include "LinkedList.h"

using namespace std;

// recursively
node* mergeRecursive(node* a,node *b){
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
    head->next = mergeRecursive(a,b);
  }
  else {
    head = b;
    b = b->next;
    head->next = mergeRecursive(a,b);
  }

  return head;
}

// used with iterative merge
void insertAtTail(node** tail,node** list){
  // to hold the node to be inserted
  node* temp = *list;

  // move the list ahead
  *list = (*list)->next;

  // add the node to the end
  temp->next = *tail;
  *tail = temp;
}

// iteratively [ very good for double pointer revision ]
node* mergeIterative(node* a,node *b){
  node* head = nullptr;
  node** tail = &head;

  while(true){
    if(a == nullptr){
      *tail = b;
      break;
    }
    if(b == nullptr){
      *tail = a;
      break;
    }

    if(a->data <= b->data)
      insertAtTail(tail,&a);
    else insertAtTail(tail,&b);

    // very important, check notes for explanation
    tail = &((*tail)->next);
  }
  return head;
}

int main(){
  node* head1 = nullptr;
  readList(head1);
  display(head1);
  cout<<"\n";
  node* head2 = nullptr;
  readList(head2);
  display(head2);
  cout<<"\n";

  node* head;
  // mergesort the list
  head = mergeIterative(head1,head2);
  // display the result
  display(head);
  cout<<"\n";

  return 0;
}
