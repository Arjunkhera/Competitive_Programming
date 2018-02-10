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
node* removeElements(node* head, int val){
    if(head == nullptr)
      return head;

    node* newHead = new node(0);
    node* prev = newHead;
    node* cur = head;
    node* temp;

    while(cur != nullptr){
      if(cur->data == val){
        temp = cur;
        cur = cur->next;
        prev->next = cur;
        delete temp;
        continue;
      }
      prev->next = cur;
      prev = cur;
      cur = cur->next;
    }

    return newHead->next;
}


int main(){

  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  head = removeElements(head,6);

  display(head);
  cout<<"\n";
  return 0;
}

/*
input
1 2 4 9 2 6 6 6 -1
6 6 6 6 6 6 2 6 -1
*/
