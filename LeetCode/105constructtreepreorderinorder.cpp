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

tree* solve(vector<int>& preorder,int start,int finish,vector<int>& inorder,int st,int fn){

  // base case
  if(start == finish){
    tree* temp = new tree(preorder[start]);
    //cout<<"temp : "<<temp->data<<"\n";
    return temp;
  }

  int search = preorder[start];
  int i = st;
  for(;i<=fn;i++)
    if(inorder[i] == search)
      break;

  tree* root = new tree(preorder[start]);
  //std::cout<<"root : "<<root->data<<"\n";

  int j = start;
  // check for left subtree
  if(i > st){
    while(preorder[j] != inorder[i-1])
      j++;

    //std::cout<<"lj : "<<j<<" li : "<<i<<"\n";
    root->left = solve(preorder,start+1,j,inorder,st,i-1);
  }

  // check for right subtree
  if(i < fn){
    //std::cout<<"j : "<<j<<" i : "<<i<<"\n";
    root->right = solve(preorder,j+1,finish,inorder,i+1,fn);
  }

  return root;
}

// solution function
tree* buildTree(vector<int>& preorder, vector<int>& inorder){

  if(preorder.empty())
    return nullptr;

  return solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
}

int main(){

  vector<int> preorder;
  vector<int> inorder;
  int data;

  cin>>data;
  while(data != -1){
    preorder.push_back(data);
    std:cin>>data;
  }

  cin>>data;
  while(data != -1){
    inorder.push_back(data);
    std::cin>>data;
  }

  tree* root = buildTree(preorder,inorder);
  //displayLevelOrder(root);
  displayInOrder(root);
  std::cout<<"\n";

  return 0;
}
