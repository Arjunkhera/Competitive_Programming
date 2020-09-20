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
node* reverseBetween(node* head, int m, int n){

  if(head == nullptr || head->next == nullptr)
    return head;

  node* start = nullptr;
  node* cur = head;
  int length = 1;
  while(length<m){
    start = cur;
    cur = cur->next;
    length++;
    }

  node* last = cur;
  node* tail = nullptr;
  node* temp;
  while(length <= n){
    temp = cur;
    cur = cur->next;
    temp->next = tail;
    tail = temp;
    length++;
  }

  // join the head of reversed list
  if(start == nullptr)
    head = tail;
  else start->next = tail;

  // join the tail of the reversed list
  last->next = cur;

  return head;
}

int main(){

  node* head = nullptr;
  readList(head);
  int m,n;
  cin>>m>>n;
  display(head);
  cout<<"\n";

  head = reverseBetween(head,m,n);

  display(head);
  cout<<"\n";

  return 0;
}

/*
input
5 4 3 2 1 -1
2 4
*/
