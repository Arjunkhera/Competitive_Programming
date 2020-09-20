#include "LinkedList.h"

// Three ways to pass the head pointer
// Pass the head pointer by reference : Easiest and will be used throughout the code
void insertAtHead(node* &head,int data){
  node* newNode = new node(data);
  newNode->next = head;
  head = newNode;
}

// Pass the head pointer and return the changed head
node* insertAtHead(node* head,long data){
  // long used to prevent function overloading error with (node*&,int)
  node* newNode = new node(data);
  newNode->next = head;
  head = newNode;
  return head;
}

// Pass a pointer to the head pointer
void insertAtHead(node** head,int data){
  node* newNode = new node(data);
  newNode->next = *head;
  *head = newNode;
}

// insert data at tail
void insertAtTail(node* &head,int data){
  node* newNode = new node(data);
  if(head == nullptr){
    head = newNode;
    return;
  }

  node *temp = head;
  while(temp->next != nullptr)
    temp = temp->next;
  temp->next = newNode;
}

// returns the node previous to the node whose data is given
node* findNode(node* head,int data){
  if(head == nullptr)
    return nullptr;

  if(head->data == data)
    return head;

  node* prev = head;
  while(prev->next != nullptr && prev->next->data != data)
    prev = prev->next;

  if(prev->next == nullptr)
    return nullptr;

  return prev;
}

// to delete an element from the list
bool removeElement(node* &head,int data){
  node* prev = findNode(head,data);
  if(prev == nullptr)
    return false;

  node* cur;
  if(prev == head){
    cur = prev;
    head = prev->next;
  }
  else {
    cur = prev->next;
    prev->next = cur->next;
  }

  delete cur;
  return true;
}

// read data untill you encounter -1
void readList(node* &head){
  int x;
  std::cin>>x;

  while(x!=-1){
    // for explanation of concepts

    // pass by reference
    insertAtHead(head,x);

    // return pointer
    //head = insertAtHead(head,x);

    // pass double pointer
    //insertAtHead(&head,x);
    std::cin>>x;
  }
}

// print the list
void display(node* head){
  while(head != nullptr){
    std::cout<<head->data<<" ";
    head = head->next;
  }
}

// Find length recursively
int lengthRecursive(node* head){
  if(head == nullptr)
    return 0;

  return 1+lengthRecursive(head->next);
}

// Find length iteratively
int lengthIterative(node* head){
  int length = 0;
  while(head != nullptr){
    length++;
    head = head->next;
  }

  return length;
}
