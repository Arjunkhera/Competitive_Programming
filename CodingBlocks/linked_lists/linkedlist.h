#ifndef __linkedlist_H_INCLUDED__
#define __linkedlist_H_INCLUDED__

#include<iostream>

template<typename t>
class node{
public:
  t data;
  node<t> *next;
  node(t n):data(n),next(nullptr){}
};

template<typename t>
void insertAtHead(node<t>* &head,t data){
  node<t> *newNode = new node<t>(data);
  newNode->next = head;
  head = newNode;
}

template<typename t>
void readList(node<t>* &head){
  t data;
  while(1){
    std::cin>>data;
    if(data == -1)
      break;
    insertAtHead(head,data);
  }
}

template<typename t>
void display(node<t> *head){
  while(head != nullptr){
    std::cout<<head->data<<" ";
    head = head->next;
  }
}

template<typename t>
bool deleteNode(node<t>* &head,t data){
  node<t> *prev = nullptr;
  node<t> *cur = head;

  while(cur != nullptr && cur->data != data){
    prev = cur;
    cur = cur->next;
  }

  if(cur == nullptr)
    return false;
  if(cur == head){
    head = nullptr;
    return false;
  }

  prev->next = cur->next;
  delete cur;
  return true;
}

#endif
