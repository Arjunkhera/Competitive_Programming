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
node *getIntersectionNode(node *headA, node *headB){

  if(headA == nullptr || headB == nullptr)
    return nullptr;

  bool flag = false;
  node* first = headA;
  node* second = headB;
  node* tail = nullptr;

  while( first != second){

    if(first == nullptr)
      first = headB;
    else first = first->next;

    if(second == nullptr)
      second = headA;
    else second = second->next;
  }

  return first;
}

int main(){

  node* head1 = nullptr;
  readList(head1);
  display(head1);
  cout<<"\n";

  node* head2 = nullptr;
  readList(head2);
  display(head2);
  cout<<"\n";

  head2->next = head1;
  node* intersect = getIntersectionNode(head1,head2);

  cout<<intersect->data<<"\n";

  return 0;
}

/*
input
1 2 3 2 1 -1
1 2 2 1 -1
1 2 1 -1
1 1 -1
1 -1
*/
