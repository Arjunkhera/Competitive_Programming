// leetcode question 111

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

// with newline after each level
void displayLevelOrder(tree* root){
  if(root == nullptr)
    return;

  std::queue<tree*> nodes;
  nodes.push(root);
  nodes.push(nullptr);
  tree* temp;

  while(1){
    temp = nodes.front();
    nodes.pop();

    if(temp == nullptr && nodes.empty())
      break;
    if(temp == nullptr){
      std::cout<<"\n";
      nodes.push(nullptr);
      continue;
    }

    std::cout<<temp->data<<" ";
    if(temp->left != nullptr)
      nodes.push(temp->left);
    if(temp->right != nullptr)
      nodes.push(temp->right);
  }
}

int minDepth(tree* root){
  if(root == nullptr) return 0;

  if(root->left == nullptr && root->right == nullptr) return 1;
  if(root->left == nullptr) return (1+minDepth(root->right));
  else if(root->right == nullptr) return (1+minDepth(root->left));
  else return min(1+minDepth(root->left),1+minDepth(root->right));
}

int main(){

  tree* root;
  readLevelOrder(root);

  // displayLevelOrder(root);
  cout<<minDepth(root)<<endl;

  return 0;
}

// 5 4 8 11 -1 13 4 7 2 -1 -1 5 1 -1 -1 -1 -1 -1 -1 -1 -1
