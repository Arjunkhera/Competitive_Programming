#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
void displaypreOrder(tree* root){
  if(root == nullptr)
    return;

  std::cout<<root->data<<" ";
  displaypreOrder(root->left);
  displaypreOrder(root->right);
}

// solution function
vector<int> preorderTraversal(tree* root){
  vector<int> answer;
  if(root == nullptr) return answer;

  tree* cur = root;
  stack<tree*> stk;
  stk.push(root);
  while(!stk.empty()){
    cur = stk.top();  stk.pop();
    answer.push_back(cur->data);
    if(cur->right != nullptr) stk.push(cur->right);
    if(cur->left != nullptr) stk.push(cur->left);
  }
  return answer;
}

int main(){

  tree* root = nullptr;
  readLevelOrder(root);

  displaypreOrder(root);
  std::cout<<"\n-----compare-------\n";
  vector<int> answer = preorderTraversal(root);
  for(auto i : answer)
    std::cout<<i<<" ";
  std::cout<<"\n";

  return 0;
}

/*
1 2 3 5 6 7 8 -1 -1 -1 -1 -1 -1 -1 -1
*/
