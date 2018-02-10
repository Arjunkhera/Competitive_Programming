#include<iostream>

using namespace std;

// linked list
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

// solution function
void deleteNode(node* cur){
  // this will not work for tail element
  if(cur == nullptr || cur->next == nullptr)
    return;

  // store pointer to next node
  node * temp = cur->next;
  // copy next node contents to current node
  *cur = *temp;

  // delete the next node
  delete temp;
}

int main(){

  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  deleteNode(head->next->next->next);

  display(head);
  cout<<"\n";
  return 0;
}

/*
input
3 9 10 2 1 8 3 4 -1
*/
