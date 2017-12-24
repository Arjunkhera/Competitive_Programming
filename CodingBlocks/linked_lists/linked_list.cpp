#include<iostream>

using namespace std;

class node{
public:
  int data;
  node* next;
  node(int n=0):data(n),next(nullptr){}
};

void insertAtHead(node* &head,int data){
  node *newNode = new node(data);
  newNode->next = head;
  head = newNode;
}

void readBunch(node* &head){
  int temp_data;
  while(1){
    cin>>temp_data;
    if(temp_data == -1)
      break;
    insertAtHead(head,temp_data);
  }
}

void display(node *head){
  while(head != nullptr){
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<"\n";
}

istream& operator>>(istream &is,node* &head){
  readBunch(head);
  return is;
}

ostream& operator<<(ostream &os,node* &head){
  display(head);
  return os;
}

node* reverseList_recursion(node *head){
  if(head == nullptr || head->next == nullptr){
    return head;
  }

  node *temp_head = reverseList_recursion(head->next);
  head->next->next = head;
  head->next = nullptr;
  return temp_head;
}

node* midpointList(node *head){

  node *slow=head;
  node *fast=head->next;

  while(fast->next != nullptr && fast!= nullptr){
    //cout<<slow->data<<" "<<fast->data<<"\n";
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

node* merge(node *a,node *b){
  if(a == nullptr)
    return b;
  if(b == nullptr)
    return a;

  node *temp;
  if(a->data < b->data){
    temp = a;
    temp->next = merge(a->next,b);
  }
  else{
    temp = b;
    temp->next = merge(a,b->next);
  }
  return temp;
}

node* mergeSort(node *head){
  if(head == nullptr || head->next == nullptr)
    return head;

  node* mid = midpointList(head);
  node *a = head;
  node *b = mid->next;
  mid->next = nullptr;

  a = mergeSort(a);
  b = mergeSort(b);
  return merge(a,b);
}

int main(){
  node *heada = NULL;
  node *headb = NULL;

  cin>>heada;
  heada = mergeSort(heada);
  cout<<heada;
  /*
  cin>>heada>>headb;
  node *merge_head = merge(heada,headb);
  cout<<merge_head;
  */

  /*
  //cout<<head;
  //head = reverseList_recursion(head);
  cout<<head;

  node *mid = midpointList(head);
  cout<<mid->data<<"\n";
  */
  return 0;
}
