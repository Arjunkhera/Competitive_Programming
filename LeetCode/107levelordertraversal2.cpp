#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
vector<vector<int>> levelOrder(tree* root){

  vector<vector<int>> answer;
  if(root == nullptr)
    return answer;

  tree* temp;
  queue<tree*> nodes;
  nodes.push(root);
  nodes.push(nullptr);
  vector<int> level;

  while(!nodes.empty()){
    temp = nodes.front();
    nodes.pop();

    if(temp == nullptr && nodes.empty()){
      answer.push_back(level);
      break;
    }
    if(temp == nullptr){
      nodes.push(nullptr);
      answer.push_back(level);
      level.clear();
      continue;
    }
    level.push_back(temp->data);
    if(temp->left != nullptr)
      nodes.push(temp->left);
    if(temp->right != nullptr)
      nodes.push(temp->right);
  }
  reverse(answer.begin(),answer.end());
  return answer;
}

int main(){

  tree* root = nullptr;
  readLevelOrder(root);

  vector<vector<int>> answer = levelOrder(root);
  for(int i = 0;i< answer.size();i++){
    for(auto j = answer[i].begin();j!= answer[i].end();j++)
      std::cout<<*j<<" ";
    std::cout<<"\n";
  }

  return 0;
}

// 4 3 7 2 5 6 9 -1 -1 -1 -1 -1 -1 -1 -1
