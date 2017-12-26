#ifndef __tree_H_INCLUDED__
#define __tree_H_INCLUDED__

#include<iostream>
#include<queue>

template<typename t>
class node{
public:
  t data;
  node *left;
  node *right;

  node(t dat = 0):data(dat),left(nullptr),right(nullptr){}
};

template<typename t>
node<t>* input(node<t> *root){
  int dat;
  std::cin>>dat;

  if(dat == -1)
    return nullptr;

  root = new node<t>(dat);
  root->left = input(root->left);
  root->right = input(root->right);

  return root;
}

template<typename t>
node<t>* inputLevelOrder(node<t> *root){
  t dat;
  std::cin>>dat;
  if(dat == -1)
    return nullptr;
  root = new node<t>(dat);
  node<t> *temp;

  std::queue<node<t>*> nodeList;
  nodeList.push(root);

  while(!nodeList.empty()){
    temp = nodeList.front();
    nodeList.pop();

    // check for left child
    std::cin>>dat;
    if(dat != -1){
      temp->left = new node<t>(dat);
      nodeList.push(temp->left);
    }
    else temp->left = nullptr;

    // check for right child
    std::cin>>dat;
    if(dat != -1){
      temp->right = new node<t>(dat);
      nodeList.push(temp->right);
    }
    else temp->right = nullptr;
  }
  return root;
}

template<typename t>
void displayPostorder(node<t> *root){
  if(root == nullptr)
    return;

  displayPostorder(root->left);
  displayPostorder(root->right);
  std::cout<<root->data<<" ";
}

template<typename t>
void displayPreorder(node<t> *root){
  if(root == nullptr)
    return;

  std::cout<<root->data<<" ";
  displayPreorder(root->left);
  displayPreorder(root->right);
}

template<typename t>
void displayInorder(node<t> *root){

  if(root == nullptr)
    return;

  displayInorder(root->left);
  std::cout<<root->data<<" ";
  displayInorder(root->right);
}

template<typename t>
void displayLevelorderIterative(node<t> *root){
  if(root == nullptr)
    return;

  std::queue<node<t>*> nodeList;
  nodeList.push(root);
  nodeList.push(nullptr);
  node<t> *temp;

  while(!nodeList.empty()){
    temp = nodeList.front();
    nodeList.pop();

    if(temp == nullptr){
        if(nodeList.empty())
          break;
        std::cout<<"\n";
        nodeList.push(nullptr);
        continue;
    }

    std::cout<<temp->data<<" ";
    if(temp->left != nullptr)
      nodeList.push(temp->left);
    if(temp->right != nullptr)
      nodeList.push(temp->right);
  }
};

void displayLevelorderRecursive(){};

template<typename t>
t getHeight(node<t> *root){
  if(root == nullptr)
    return 0;

  return 1+std::max(getHeight(root->left),getHeight(root->right));
}

template<typename t>
t getDiameter(node<t> *root){
  if(root == nullptr)
    return 0;

  t curDia = getHeight(root->left)+getHeight(root->right);
  return std::max(std::max(getDiameter(root->left),getDiameter(root->right)),curDia);
}

template<typename t>
std::pair<t,t> getDiameterFast(node<t> *root){
  std::pair<t,t> left,right,answer;

  if(root == nullptr){
    left.first = 0;
    left.second = 0;
    return left;
  }

  left = getDiameterFast(root->left);
  right = getDiameterFast(root->right);

  answer.second = std::max(left.second,right.second) + 1;
  answer.first = left.second + right.second;
  answer.first =  std::max(std::max(left.first,right.first),answer.first);

  return answer;
}

void test_header(){
  std::cout<<"Hello world\n";
}

template<typename t>
void generateMirror(node<t> *root){

  if(root == nullptr)
    return;

  std::swap(root->left,root->right);

  generateMirror(root->left);
  generateMirror(root->right);
}

template<typename t>
bool identicalTrees(node<t> *root,node<t> *root_second){
  // base case
  if(root == nullptr && root_second == nullptr)
    return true;

  if(root != nullptr && root_second != nullptr)
    if(root->data == root_second->data && identicalTrees(root->left,root_second->left) && identicalTrees(root->right,root_second->right))
      return true;

  return false;
}

#endif
