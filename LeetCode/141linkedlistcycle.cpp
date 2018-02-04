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

// check out the linked list folder for better insight
// solution function
bool hasCycle(node *head){
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

  return flag;
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
