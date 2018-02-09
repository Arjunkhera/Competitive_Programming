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

node* findMidpoint(node* head){

  if(head == nullptr || head->next == nullptr)
    return head;

  node* slow = head;
  node* fast = head;

  while(fast->next != nullptr && fast->next->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

node* merge(node* leftlist,node* rightlist){
  node* head = new node(-1);
  node* tail = head;

  while(leftlist != nullptr && rightlist != nullptr)
    if(leftlist->data < rightlist->data){
      tail->next = leftlist;
      tail = leftlist;
      leftlist = leftlist->next;
      tail->next = nullptr;
    }
    else{
      tail->next = rightlist;
      tail = rightlist;
      rightlist = rightlist->next;
      tail->next = nullptr;
    }

  if(leftlist != nullptr)
    tail->next = leftlist;
  if(rightlist != nullptr)
    tail->next = rightlist;

  return head->next;
}

// solution function
node* sortList(node* head){

  if(head == nullptr || head->next == nullptr)
    return head;

  node* mid = findMidpoint(head);

  node* leftlist = head;
  node* rightlist = mid->next;
  mid->next = nullptr;

  leftlist = sortList(leftlist);
  rightlist = sortList(rightlist);
  return merge(leftlist,rightlist);
}

int main(){

  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  head = sortList(head);

  display(head);
  cout<<"\n";

  return 0;
}

/*
input
3 9 10 2 1 8 3 4 -1
*/
