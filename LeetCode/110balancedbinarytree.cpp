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

pair<bool,int> solve(tree* root){
  if(root == nullptr) return make_pair(true,0);

  pair<bool,int> left = solve(root->left);
  pair<bool,int> right = solve(root->right);
  pair<bool,int> answer(false,0);
  if(left.first == false || right.first == false) return answer;
  if(abs(left.second - right.second) > 1) answer.first = false; else answer.first = true;
  answer.second = max(left.second,right.second)+1;
  return answer;
}

int withoutpairs(tree* root){
  if(root == nullptr) return 0;

  int left = withoutpairs(root->left);
  if(left == -1) return -1;
  int right = withoutpairs(root->right);
  if(right == -1) return -1;

  if(abs(left - right) > 1) return -1;
  return max(left,right)+1;
}

bool isBalanced(tree* root){
  // pair<bool,int> answer = solve(root);
  // return answer.first;
  return (withoutpairs(root) == -1) ? false:true;
}

int main(){

  tree* root;
  readLevelOrder(root);

  if(isBalanced(root)) cout<<"Yes\n"; else cout<<"No\n";

  return 0;
}

// 5 4 8 11 -1 13 4 7 2 -1 -1 -1 1 -1 -1 -1 -1 -1 -1
