// leetcode question 314

#include <iostream>
#include <queue>
#include <climits>
#include <map>
#include <vector>

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
vector<vector<int>> verticalOrder(tree* root){
  vector<vector<int>> answer;
  if(root == nullptr) return answer;

  map<int,vector<int>> lines;
  queue<pair<tree*,int>> nodes;
  nodes.emplace(root,0);
  pair<tree*,int> element; int linenumber; tree* temp;

  while(!nodes.empty()){
    element = nodes.front(); temp = element.first; linenumber = element.second;
    nodes.pop();

    lines[linenumber].push_back(temp->data);
    if(temp->left != nullptr) nodes.emplace(temp->left,linenumber-1);
    if(temp->right != nullptr) nodes.emplace(temp->right,linenumber+1);
  }

  for(auto i:lines) answer.push_back(i.second);
  return answer;
}

int main(){

  tree* root;
  readLevelOrder(root);

  vector<vector<int>> answer = verticalOrder(root);
  for(auto i:answer) { for(auto j:i) cout<<j<<" "; cout<<endl; }

  cout<<endl;

  return 0;
}

/*
6 3 7 2 5 -1 9 -1 -1 -1 -1 -1 -1
*/
