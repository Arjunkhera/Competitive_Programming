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
node* deleteDuplicates(node* head){

  // list is empty or has a single element
  if(head == nullptr || head->next == nullptr)
    return head;

  node* newHead = new node(-1);
  node* tail = newHead;
  node* cur = head;
  node* temp;
  int curdata;
  bool flag = false;

  while(cur->next != nullptr){
    if(flag && curdata == cur->data){
      temp = cur;
      cur = cur->next;
      delete temp;
      continue;
    }
    flag = false;
    curdata = cur->data;
    if(cur->data == cur->next->data){
      curdata = cur->data;
      flag = true;
      continue;
    }
    tail->next = cur;
    tail = cur;
    cur = cur->next;
  }

  if(curdata == cur->data)
    tail->next = nullptr;
  else tail->next = cur;

  return newHead->next;
}

int main(){

  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  head = deleteDuplicates(head);
  display(head);
  cout<<"\n";

  return 0;
}
