#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

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
vector<vector<int>> zigzagLevelOrder(tree* root){

  vector<vector<int>> answer;
  if(root == nullptr)
    return answer;

  bool flag = true;
  bool cur = true;
  tree* temp;
  stack<tree*> stk;
  stk.push(root);
  stack<tree*> tempstk;
  vector<int> level;

  while(1){
    if(stk.empty() && tempstk.empty())
      break;
    if(cur){
      while(!stk.empty()){
        temp = stk.top();
        stk.pop();
        level.push_back(temp->data);

        if(flag){
          if(temp->left != nullptr)
            tempstk.push(temp->left);
          if(temp->right != nullptr)
            tempstk.push(temp->right);
        }
        else{
          if(temp->right != nullptr)
            tempstk.push(temp->right);
          if(temp->left != nullptr)
            tempstk.push(temp->left);
        }
      }
      answer.push_back(level);
      level.clear();
      flag = !flag;
      cur = !cur;
    }
    else {
      while(!tempstk.empty()){
        temp = tempstk.top();
        tempstk.pop();
        level.push_back(temp->data);

        if(flag){
          if(temp->left != nullptr)
            stk.push(temp->left);
          if(temp->right != nullptr)
            stk.push(temp->right);
        }
        else{
          if(temp->right != nullptr)
            stk.push(temp->right);
          if(temp->left != nullptr)
            stk.push(temp->left);
        }
      }
      answer.push_back(level);
      level.clear();
      flag = !flag;
      cur = !cur;
    }
  }

  return answer;
}

vector<vector<int>> zigzagLevelOrder_deque(tree* root){
  vector<vector<int>> answer; vector<int> level;
  if(root == nullptr) return answer;

  deque<tree*> dq; bool flag = true; tree* temp;
  dq.push_front(root); dq.push_back(nullptr);

  while(1){
    if(flag){
      temp = dq.front(); dq.pop_front();
      if(temp == nullptr && dq.empty()) { answer.push_back(level); break; }
      if(temp == nullptr) { answer.push_back(level); level.clear(); dq.push_front(nullptr); flag = !flag; continue; }
      level.push_back(temp->data);
      if(temp->left != nullptr) dq.push_back(temp->left);
      if(temp->right != nullptr) dq.push_back(temp->right);
    }
    else {
      temp = dq.back(); dq.pop_back();
      if(temp == nullptr && dq.empty()) { answer.push_back(level); break; }
      if(temp == nullptr) { answer.push_back(level); level.clear(); dq.push_back(nullptr); flag = !flag; continue; }
      level.push_back(temp->data);
      if(temp->right != nullptr) dq.push_front(temp->right);
      if(temp->left != nullptr) dq.push_front(temp->left);
    }
  }
  return answer;
}

int main(){

  tree* root = nullptr;
  readLevelOrder(root);

  vector<vector<int>> answer = zigzagLevelOrder(root);
  for(int i = 0;i< answer.size();i++){
    for(auto j = answer[i].begin();j!= answer[i].end();j++)
      std::cout<<*j<<" ";
    std::cout<<"\n";
  }

  return 0;
}

// 4 3 7 2 5 6 9 -1 -1 -1 -1 -1 -1 -1 -1
