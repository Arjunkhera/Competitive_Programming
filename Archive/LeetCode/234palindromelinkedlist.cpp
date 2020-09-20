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
// O(n) complexity, basically 3*n and O(1) space
bool isPalindrome(node* head){
  bool flag = true;

  if(head == nullptr || head->next == nullptr)
    return flag;

  int length = 0;
  node* cur = head;
  while(cur != nullptr){
    cur = cur->next;
    length++;
  }

  // split list from middle
  int m = 1;
  cur = head;
  while(m != (length/2)){
    cur = cur->next;
    m++;
  }
  node* temp;
  temp = cur;
  if(length%2 != 0)
    cur = cur->next->next;
  else
    cur = cur->next;
  temp->next = nullptr;

  // reverse the remaining second half of list
  node* prev = nullptr;
  while(cur != nullptr){
    temp = cur;
    cur = cur->next;
    temp->next = prev;
    prev = temp;
  }

  // compare both halves
  node* first = head;
  node* second = prev;
  while(first != nullptr){

    if(first->data != second->data){
      flag = false;
      break;
    }
    first = first->next;
    second = second->next;
  }

  return flag;
}

int main(){

  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  cout<<isPalindrome(head)<<"\n";

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
