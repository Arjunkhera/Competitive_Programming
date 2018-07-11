// leetcode question 173
// just declare the stack globally cause in interviewbit they have not allowed
// declaration of private variables

#include <iostream>
#include <queue>
#include <climits>
#include <stack>

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

// solution function
class BSTIterator {
    stack<tree*> stk;
public:
    BSTIterator(tree *root){
      while(root != nullptr) {stk.push(root); root = root->left; }
    }

    /** @return whether we have a next smallest number */
    bool hasNext(){
      if(stk.empty()) return false;
      return true;
    }

    /** @return the next smallest number */
    int next(){
      if(!hasNext()) return -1;

      tree *temp = stk.top(); stk.pop();
      int answer = temp->data;
      temp = temp->right;
      while(temp != nullptr) {stk.push(temp); temp = temp->left;}
      return answer;
    }
};

// driver function
int main(){

  tree* root;
  readLevelOrder(root);

  BSTIterator i = BSTIterator(root);
  while (i.hasNext()) cout << i.next();
  return 0;
}

/*
3 5 1 6 2 0 8 -1 -1 7 4 -1 -1 -1 -1 -1 -1 -1 -1
*/
