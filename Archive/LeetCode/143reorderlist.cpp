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

void reorderList(node *head){
  if(head == nullptr || head->next == nullptr) return;

  node *prev,*temp,*cur,*slow = head,*fast = head;
  // find the midpoint
  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
  }

  // reverse the second half of the list
  cur = slow->next; prev = nullptr; slow->next = nullptr;
  while(cur){
    temp = cur; cur = cur->next;
    temp->next = prev; prev = temp;
  }

  // merge the lists alternatively
  cur = head;
  while(prev){
    temp = cur->next;
    cur->next = prev;
    cur = temp;
    temp = prev->next;
    prev->next = cur;
    prev = temp;
  }
}

int main(){

  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  reorderList(head);
  display(head);
  cout<<"\n";

  return 0;
}
