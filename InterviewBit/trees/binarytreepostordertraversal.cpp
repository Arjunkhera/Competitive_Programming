// leetcode question 145

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
  if(!root) return answer;

  tree *temp,*prev = nullptr,*cur = root;
  stack<tree*> stk;
  while(cur || !stk.empty())
    if(cur){ stk.push(cur); cur = cur->left; }
    else{
      temp = stk.top();
      if(!temp->right || temp->right == prev){ prev = temp; answer.push_back(temp->data); stk.pop(); }
      else cur = temp->right;
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
