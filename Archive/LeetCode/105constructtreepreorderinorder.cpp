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
  if(start > finish) return nullptr;
  if(start == finish){ tree* temp = new tree(preorder[start]); return temp; }

  // recursive case
  int temp,search = preorder[start],i = st,j = start;
  for(;i <= fn;i++) if(inorder[i] == search) break;

  tree* root = new tree(preorder[start]); temp = i-st;
  root->left = solve(preorder,start+1,j+temp,inorder,st,i-1);
  root->right = solve(preorder,j+temp+1,finish,inorder,i+1,fn);
  return root;
}

// solution function
tree* buildTree(vector<int>& preorder, vector<int>& inorder){

  if(preorder.empty() || preorder.size() != inorder.size()) return nullptr;

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
