#ifndef __Tree_H_INCLUDED__
#define __Tree_H_INCLUDED__

#include<iostream>
#include<queue>
#include<iomanip>

struct tree{
  int data;
  tree* left;
  tree* right;
  tree(int dat):data(dat),left(nullptr),right(nullptr){}
};

void readTree(tree*&);
void readLevelOrder(tree*&);
void displayInOrder(tree*);
void displayPreOrder(tree*);
void displayPostOrder(tree*);
void displayLevelOrder(tree*);
void displayKthLevel(tree*,int,int);
void displayLevelorderRecursive(tree*);
void displayBeautiful(tree*);
int countNodes(tree*);
int getHeight(tree*);
void getDepth(tree*,int,int&,int);
int getDiameter(tree*);
std::pair<int,int> getDiameterFast(tree*);

#endif
