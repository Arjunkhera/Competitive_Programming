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
node* partition(node* head, int x){
  if(head == nullptr)
    return head;

  node* smallList = new node(-1);
  node* small = smallList;
  node* largeList = new node(-1);
  node* large = largeList;
  node* cur = head;

  while(cur != nullptr)
    if(cur->data < x){
      small->next = cur;
      small = cur;
      cur = cur->next;
      small->next = nullptr;
      continue;
    }
    else{
      large->next = cur;
      large = cur;
      cur = cur->next;
      large->next = nullptr;
      continue;
    }

  small->next = largeList->next;
  head = smallList->next;

  return head;
}

int main(){

  node* head = nullptr;
  readList(head);

  head = partition(head,3);

  display(head);
  cout<<"\n";

  return 0;
}
