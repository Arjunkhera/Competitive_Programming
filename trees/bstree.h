#ifndef __bstree_H_INCLUDED__
#define __bstree_H_INCLUDED__

#include<iostream>
#include<climits>
#include<queue>

node<t>* insertNode(node<t>*,t);
node<t>* input(node<t>*);
node<t>* search(node<t>*,t);
node<t>* LeftBiggest(node<t>*);
node<t>* deleteNode(node<t>*,t);
void displayPostorder(node<t>*);
void displayPreorder(node<t>*);
void displayInorder(node<t>*);
void displayLevelorderIterative(node<t>*);
void displayKthLevel(node<t>*,int,int);
void displayLevelorderRecursive(node<t>*);
t countNodes(node<t>*);
t getHeight(node<t>*);
t getDiameter(node<t>*);
std::pair<t,t> getDiameterFast(node<t>*);
bool checkBST(node<t>*,int,int);
void generateMirror(node<t>*);
bool identicalTrees(node<t>*,node<t>*);
void test_header();

template<typename t>
class node{
public:
  t data;
  node *left;
  node *right;

  node(t dat = 0):data(dat),left(nullptr),right(nullptr){}
};

template<typename t>
node<t>* insertNode(node<t> *root,t data){
  if(root == nullptr){
    return new node<t>(data);
  }

  if(root->data >= data)
    root->left = insertNode(root->left,data);
  else root->right = insertNode(root->right,data);

  return root;
}

template<typename t>
node<t>* input(node<t> *root){
  int dat;
  std::cin>>dat;

  if(dat == -1)
    return root;

  root = insertNode(root,dat);
  input(root);
}

template<typename t>
node<t>* search(node<t> *root,t find){
  if(root == nullptr)
    return false;

  if(root->data == find)
    return root;

  if(root->data > find)
    return search(root->left,find);
  else return search(root->right,find);
}

template<typename t>
node<t>* LeftBiggest(node<t> *root){
  if(root->right == nullptr)
    return root;

  return LeftBiggest(root->right);
}

template<typename t>
node<t>* deleteNode(node<t> *root,t data){
  if(root == nullptr)
    return nullptr;

  if(root->data == data){
    if(root->left == nullptr && root->right == nullptr){
      delete root;
      return nullptr;
    }

    node<t> *temp;
    if(root->left != nullptr && root->right == nullptr){
      temp = root->left;
      delete root;
      return temp;
    }
    if(root->right != nullptr && root->left == nullptr){
      temp = root->right;
      delete root;
      return temp;
    }

    temp = LeftBiggest(root->left);
    root->data = temp->data;
    root->left = deleteNode(root->left,temp->data);
  }
  else if(root->data > data)
    root->left = deleteNode(root->left,data);
  else
    root->right = deleteNode(root->right,data);

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

template<typename t>
void displayKthLevel(node<t> *root,int displaylevel,int curlevel){
  if(root == nullptr)
    return;

  if(curlevel == displaylevel)
    std::cout<<root->data<<" ";

  displayKthLevel(root->left,displaylevel,curlevel+1);
  displayKthLevel(root->right,displaylevel,curlevel+1);
}

template<typename t>
void displayLevelorderRecursive(node<t> *root){
  int maxLevel = getHeight(root);

  for(int i=1;i<=maxLevel;i++){
    displayKthLevel(root,i,1);
    std::cout<<"\n";
  }
}

template<typename t>
t countNodes(node<t> *root){
  if(root == nullptr)
    return 0;

  return 1+countNodes(root->left)+countNodes(root->right);
}

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

template<typename t>
bool checkBST(node<t> *root,int min=INT_MIN,int max=INT_MAX){
  if(root == nullptr)
    return true;

  if(root->data > min && root->data < max && checkBST(root->left,min,root->data) && checkBST(root->right,root->data,max))
    return true;

  return false;
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

void test_header(){
  std::cout<<"Hello world\n";
}

#endif
