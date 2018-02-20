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

bool checkBST(tree *root,int min,int max){
  if(root == nullptr)
    return true;

  if(root->data > min && root->data < max && checkBST(root->left,min,root->data) && checkBST(root->right,root->data,max))
    return true;

  return false;
}

// solution function
bool isValidBST(tree* root){
  // wont work in case if data is either INT_MIN or INT_MAX
  return checkBST(root,INT_MIN,INT_MAX);
  // so use LLINT_MAX and LLINT_MIN
}

bool inorder(tree* root,tree* &prev){

  // base case
  if(root == nullptr)
    return true;

  // check left subtree is BST
  if(!inorder(root->left,prev))
    return false;

  // check current node
  if(prev != nullptr && prev->data >= root->data)
    return false;
  prev = root;

  // check right subtree is BST
  return inorder(root->right,prev);
}

// preferred solution using inroder traversal
bool checkBSTindorder(tree* root){
  tree* prev = nullptr;
  return inorder(root,prev);
}

int main(){

  tree* root = nullptr;
  readLevelOrder(root);

  displayInOrder(root);
  std::cout<<"\n";

  if(isValidBST(root))
    std::cout<<"Is BST \n";
  else std::cout<<"Is not BST \n";

  return 0;
}
