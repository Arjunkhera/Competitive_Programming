#include "linkedlist.h"

int main(){
  node<int> *head = nullptr;

  // reading elements in a list
  readList(head);

  // display list
  display(head);
  std::cout<<"\n";

  // delete from list
  int dat;
  std::cin>>dat;
  if(deleteNode(head,dat))
    std::cout<<"delete successful\n";
  else std::cout<<"element not present\n";

  // display list
  display(head);
  std::cout<<"\n";

  return 0;
}
