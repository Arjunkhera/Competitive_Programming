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
node* swapPairs(node* head){

  // zero or one element
  if(head == nullptr || head->next == nullptr)
    return head;

  node* prev = head;
  node* cur = head->next->next;
  head = prev->next;

  prev->next->next = prev;
  prev->next = swapPairs(cur);

  return head;
}

int main(){

  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  head = swapPairs(head);
  display(head);
  cout<<"\n";

  return 0;
}
