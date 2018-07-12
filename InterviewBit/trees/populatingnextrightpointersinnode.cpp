// leetcode question 117

#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct tree{
  int data;
  tree* left;
  tree* right;
  tree* next;
  tree(int dat):data(dat),left(nullptr),right(nullptr),next(nullptr){}
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

void connect(tree *root){
  if(root == nullptr) return;

  queue<tree*> q; q.push(root); q.push(nullptr); tree* temp;
  while(1){
    temp = q.front(); q.pop();
    if(temp == nullptr && q.empty()) return;
    if(temp == nullptr) { q.push(nullptr); continue; }
    temp->next = q.front();
    if(temp->left != nullptr) q.push(temp->left);
    if(temp->right != nullptr) q.push(temp->right);
  }
}

// using constant space
void connectConstantSpace(tree *root){
  if(root == nullptr) return;

  for(tree* head = root; head != nullptr;){
      tree* nextrowhead = new tree(0); tree* nextrowtail = nextrowhead;
      for(tree* row = head; row != nullptr; ){
        if(row->left != nullptr){ nextrowtail->next = row->left; nextrowtail = row->left; }
        if(row->right != nullptr){ nextrowtail->next = row->right; nextrowtail = row->right; }
        row = row->next;
      }
      head = nextrowhead->next;
  }
}

int main(){

  tree* root = nullptr;
  readLevelOrder(root);

  connect(root);
  displayInOrder(root);
  return 0;
}

// 4 3 7 2 5 6 9 -1 -1 -1 -1 -1 -1 -1 -1
