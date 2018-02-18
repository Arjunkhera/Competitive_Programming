#ifndef __LinkedList_H_INCLUDED__
#define __LinkedList_H_INCLUDED__

#include<iostream>

// used struct because we are not using private here
struct node{
  int data;
  node* next;
  node(int dat):data(dat),next(nullptr){}
};

// class can also be used
/*
class node{
  int data;
  node* next;
  node(int dat):data(dat),next(nullptr){}
};
*/

void insertAtHead(node*&,int);
node* insertAtHead(node*,long);
void insertAtHead(node**,int);
void insertAtTail(node*&,int);
node* findNode(node*,int);
bool removeElement(node*&,int);
void readList(node*&);
void display(node*);
int lengthRecursive(node*);
int lengthIterative(node*);

#endif
