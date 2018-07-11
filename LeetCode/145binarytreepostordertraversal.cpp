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
void displaypostOrder(tree* root){
  if(root == nullptr)
    return;

  displaypostOrder(root->left);
  displaypostOrder(root->right);
  std::cout<<root->data<<" ";
}

// solution function
vector<int> postorderTraversal(tree* root){
  vector<int> answer;
  if(root == nullptr) return answer;

  tree* cur = root;
  stack<tree*> stk,tempstk;
  stk.push(root);
  while(!stk.empty()){
    cur = stk.top();
    if(cur->left == nullptr && cur->right == nullptr) { answer.push_back(cur->data); stk.pop(); }
    else if(tempstk.empty() || cur->data != tempstk.top()->data){
      tempstk.push(cur);
      if(cur->right != nullptr) stk.push(cur->right);
      if(cur->left != nullptr) stk.push(cur->left);
    }
    else {
      answer.push_back(cur->data);
      stk.pop(); tempstk.pop();
    }
  }
  return answer;
}

int main(){

  tree* root = nullptr;
  readLevelOrder(root);

  displaypostOrder(root);
  std::cout<<"\n-----compare-------\n";
  vector<int> answer = postorderTraversal(root);
  for(auto i : answer)
    std::cout<<i<<" ";
  std::cout<<"\n";

  return 0;
}

/*
1 2 3 5 6 7 8 -1 -1 -1 -1 -1 -1 -1 -1
*/
