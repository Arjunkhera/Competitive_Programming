// leetcode question 99

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

// helper function
void inorder(TreeNode *root,TreeNode* &prev,TreeNode* &first,vector<int> &answer){
  // base case
  if(root == nullptr)
    return;

  inorder(root->left,prev,first,answer);

  if(prev != nullptr && prev->val > root->val)
    if(first == nullptr){
      first = prev;
      answer.push_back(first->val);
      answer.push_back(root->val);
    }
    else answer[1] = root->val;
  prev = root;

  inorder(root->right,prev,first,answer);
}

// solution function
vector<int> recoverTree(tree* root){
  vector<int> answer;
  if(root == nullptr) return answer;

  TreeNode* prev = nullptr;
  TreeNode* first = nullptr;

  inorder(root,prev,first,answer);
  if(answer[0] > answer[1]) swap(answer[0],answer[1]);
  return answer;
}

int main(){

  tree* root = nullptr;
  readLevelOrder(root);

  displayInOrder(root);
  std::cout<<"\n";

  vector<int> answer = recoverTree(root);
  for(auto i:answer) cout<<i<<" "; cout<<endl;
  return 0;
}

// 4 3 7 2 5 6 9 -1 -1 -1 -1 -1 -1 -1 -1
