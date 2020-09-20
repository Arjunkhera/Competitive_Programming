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

  if(n != 0){
    return head->next;
  }

  while(fast->next != nullptr){
    prev = prev->next;
    fast = fast->next;
  }

  prev->next = prev->next->next;
  return head;
}

int main(){

  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  head = removeNthFromEnd(head,1);
  display(head);
  cout<<"\n";

  return 0;
}
