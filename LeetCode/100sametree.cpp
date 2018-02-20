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

// solution function
bool isSameTree(tree* first, tree* second){

  // base case
  if(first == nullptr && second == nullptr)
    return true;

  if(first != nullptr && second != nullptr && first->data == second->data && isSameTree(first->left,second->left) && isSameTree(first->right,second->right))
    return true;

  return false;
}

int main(){

  tree* first = nullptr;
  readLevelOrder(first);

  tree* second = nullptr;
  readLevelOrder(second);

  if(isSameTree(first,second))
    std::cout<<"Same\n";
  else std::cout<<"Different\n";

  return 0;
}

// 4 3 7 2 5 6 9 -1 -1 -1 -1 -1 -1 -1 -1
