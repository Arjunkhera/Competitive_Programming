#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct tree{
  int data;
  tree* left;
  tree* right;
  tree(int dat):data(dat),left(nullptr),right(nullptr){}
};

// input elements level wise
void readLevelOrder(tree* &root){
  std::queue<tree*> nodes;
  int dat;
  std::cin>>dat;

  // empty tree
  if(dat == -1)
    return;

  root = new tree(dat);
  nodes.push(root);
  tree* temp = nullptr;
  tree* child = nullptr;

  while(!nodes.empty()){
    temp = nodes.front();
    nodes.pop();

    // check for left child
    std::cin>>dat;
    if(dat != -1){
      child = new tree(dat);
      temp->left = child;
      nodes.push(child);
    }

    // check for right child
    std::cin>>dat;
    if(dat != -1){
      child = new tree(dat);
      temp->right = child;
      nodes.push(child);
    }
  }
}

// display has various methods
void displayInOrder(tree* root){
  if(root == nullptr)
    return;

  displayInOrder(root->left);
  std::cout<<root->data<<" ";
  displayInOrder(root->right);
}

bool isSame(tree* first, tree* second){

  // base case
  if(first == nullptr && second == nullptr)
    return true;

  if(first != nullptr && second != nullptr && first->data == second->data && isSame(first->left,second->right) && isSame(first->right,second->left))
    return true;

  return false;
}

// solution function : recursive solution
bool isSymmetric(tree* root){

  return isSame(root->left,root->right);
}

// use the concept of queue in levelorder traversal for an iterative solution
bool isSymmetric_iterative(tree* root){
  queue<tree*> q; tree* first; tree* second;
  q.push(root); q.push(root);
  while(!q.empty()){
    first = q.front(); q.pop(); second = q.front(); q.pop();
    if(first == nullptr && second == nullptr) continue;
    if(first == nullptr || second == nullptr) return false;
    if(first->data != second->data) return false;
    q.push(first->left); q.push(second->right); q.push(first->right); q.push(second->left);
  }
  return true;
}

int main(){

  tree* root = nullptr;
  readLevelOrder(root);

  if(isSymmetric(root))
    std::cout<<"Symmetric\n";
  else std::cout<<"Not Symmetric\n";

  return 0;
}

// 4 3 7 2 5 6 9 -1 -1 -1 -1 -1 -1 -1 -1
