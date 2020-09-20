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
node* insertionSortList(node* head){
  if(head == nullptr || head->next == nullptr) return head;

  node *temp,*prev,*cur = head->next;
  head->next = nullptr;

  while(cur != nullptr){
    if(head->data > cur->data){
      temp = cur;
      cur = cur->next;
      temp->next = head;
      head = temp;
      continue;
    }

    prev = head;
    // use equality to make sorting stable
    while(prev->next != nullptr && prev->next->data <= cur->data) prev = prev->next;

    temp = cur;
    cur = cur->next;
    temp->next = prev->next;
    prev->next = temp;
  }

  return head;
}

int main(){

  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  head = insertionSortList(head);

  display(head);
  cout<<"\n";

  return 0;
}

/*
input
3 9 10 2 1 8 3 4 -1
*/
