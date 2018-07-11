// leetcode question 94

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
void displayInOrder(tree* root){
  if(root == nullptr)
    return;

  displayInOrder(root->left);
  std::cout<<root->data<<" ";
  displayInOrder(root->right);
}

// solution function
vector<int> inorderTraversal(tree* root){

  vector<int> answer;
  if(root == nullptr) return answer;

  tree* cur = root;
  stack<tree*> stk;
  while(cur != nullptr){ stk.push(cur); cur = cur->left; }

  while(!stk.empty()){
    cur = stk.top();  stk.pop();
    answer.push_back(cur->data);
    cur = cur->right;

    while(cur != nullptr){ stk.push(cur); cur = cur->left; }
  }

  return answer;
}

int main(){

  tree* root = nullptr;
  readLevelOrder(root);

  displayInOrder(root);
  std::cout<<"\n-----compare-------\n";
  vector<int> answer = inorderTraversal(root);
  for(auto i : answer)
    std::cout<<i<<" ";
  std::cout<<"\n";

  return 0;
}
