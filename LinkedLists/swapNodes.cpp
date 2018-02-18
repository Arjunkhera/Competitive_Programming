#include "LinkedList.h"

using namespace std;

// Swap nodes by changing links
bool swapNodes(node* &head,int dataA,int dataB){
  if(head == nullptr)
    return false;

  node* first = findNode(head,dataA);
  node* second = findNode(head,dataB);

  if(first == nullptr || second == nullptr)
    return false;

  node* temp;
  if(first == head){
    head = first->next;

    temp = second->next;
    second->next = first;
    first->next = temp->next;

    temp->next = head;
    head = temp;
    return true;
  }

  if(second == head){
    head = second->next;
    temp = first->next;

    first->next = second;
    second->next = temp->next;

    temp->next = head;
    head = temp;
    return true;
  }

  // modifying front pointers
  temp = first->next->next;
  first->next->next = second->next->next;
  second->next->next = temp;

  // modifying back pointers
  temp = first->next;
  first->next = second->next;
  second->next = temp;

  return true;
}

int main(){
  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  // swapping 3 and 9
  (swapNodes(head,3,9))?cout<<"swap successful\n":cout<<"swap unsuccessful\n";
  display(head);
  cout<<"\n";

  // swapping 10 and 8
  (swapNodes(head,10,8))?cout<<"swap successful\n":cout<<"swap unsuccessful\n";
  display(head);
  cout<<"\n";

  return 0;
}
