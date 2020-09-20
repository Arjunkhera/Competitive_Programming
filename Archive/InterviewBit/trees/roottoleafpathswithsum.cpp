// leetcode question 113

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

void solve(tree* root,int sum,vector<int> &res,vector<vector<int>> &answer){
  if(root == nullptr) return;
  res.push_back(root->data);
  if(sum == root->data && root->left == nullptr && root->right == nullptr){ answer.push_back(res); res.pop_back(); return; }

  solve(root->left,sum-(root->data),res,answer);
  solve(root->right,sum-(root->data),res,answer);
  res.pop_back();
}

vector<vector<int>> pathSum(tree* root, int sum){
  vector<vector<int>> answer; vector<int> res;
  solve(root,sum,res,answer);
  return answer;
}

int main(){

  tree* root;
  readLevelOrder(root);

  // displayLevelOrder(root);
  int sum; cin>>sum;
  cout<<endl;
  vector<vector<int>> answer = pathSum(root,sum);
  for(int i = 0;i< answer.size();i++){
    for(auto j = answer[i].begin();j!= answer[i].end();j++)
      std::cout<<*j<<" ";
    std::cout<<"\n";
  }
  return 0;
}

// 5 4 8 11 -1 13 4 7 2 -1 -1 5 1 -1 -1 -1 -1 -1 -1 -1 -1
