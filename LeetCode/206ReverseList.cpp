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


node* reverseList(node* head){
    if(head == nullptr || head->next == nullptr)
    return head;

    node* temp = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return temp;
}

int main(){

  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  head = reverseList(head);
  display(head);
  cout<<"the end\n";

  return 0;
}
