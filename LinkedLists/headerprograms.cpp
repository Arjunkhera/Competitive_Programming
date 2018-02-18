#include "LinkedList.h"

using namespace std;

int main(){

  node* head = nullptr;

  readList(head);
  insertAtTail(head,100);
  display(head);
  cout<<"\n";
  // remove from tail
  removeElement(head,100);
  // remove from head
  removeElement(head,10);
  // remove from in-between
  removeElement(head,2);
  display(head);
  cout<<"\n";
  // Finding the length -> two methods
  int lengthrecursive = lengthRecursive(head);
  int lenghtiterative = lengthIterative(head);
  (lengthrecursive == lenghtiterative)?cout<<lengthrecursive<<"\n":cout<<"mismatch, something is wrong \n";

  return 0;
}
