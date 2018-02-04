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

// check out the linked list folder for more insight
// solution function
bool detectLoop(node* head){
  if(head == nullptr)
    return false;

  node* slow = head;
  node* fast = head;

  bool flag = false;
  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){
      flag = true;
      break;
    }
  }

  if(flag)
    return removeLoop(head);
  else return nullptr;
}

node* removeLoop(node* head){

  node* slow = head;
  node* fast = head;

  // first find the intersection point
  do{
    slow = slow->next;
    fast = fast->next->next;
  }while(slow != fast);

  slow = head;
  while(slow->next != fast->next){
      slow = slow->next;
      fast = fast->next;
  }

  // equal to is the case when the last node loops back to the first
  if(slow == fast)
      return slow;
  else return slow->next;

}

int main(){

  node* head = nullptr;
  readList(head);

  // for testing purpose
  makeLoop(head);

  if(detectLoopHash(head)){
    cout<<"Loop detected in the list\n";
    removeLoopHash(head);
    cout<<"Loop removed\n";
  }
  else cout<<"No loop present in the list\n";

  display(head);
  cout<<"\n";

  return 0;
}
