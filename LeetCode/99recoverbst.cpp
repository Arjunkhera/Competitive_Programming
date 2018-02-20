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

void inorder(tree *root,tree* &prev,tree* &first,tree* &second){
  // base case
  if(root == nullptr)
    return;

  inorder(root->left,prev,first,second);

  if(prev != nullptr && prev->data > root->data)
    if(first == nullptr){
      first = prev;
      second = root;
    }
    else {
      int temp = first->data;
      first->data = root->data;
      root->data = temp;
    }
  prev = root;

  inorder(root->right,prev,first,second);
}

// solution function
void recoverTree(tree* root){
  tree* prev = nullptr;
  tree* first = nullptr;
  tree* second = nullptr;

  inorder(root,prev,first,second);

  // the violation was between consecutive elements in Inorder
  if(second->data < first->data){
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
  }
}

int main(){

  tree* root = nullptr;
  readLevelOrder(root);

  displayInOrder(root);
  std::cout<<"\n";

  recoverTree(root);

  displayInOrder(root);
  std::cout<<"\n";

  return 0;
}

// 4 3 7 2 5 6 9 -1 -1 -1 -1 -1 -1 -1 -1
