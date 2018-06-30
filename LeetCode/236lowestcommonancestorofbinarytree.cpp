#include <iostream>
#include <vector>
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
void displayInOrder(tree* root){
  if(root == nullptr)
    return;

  displayInOrder(root->left);
  std::cout<<root->data<<" ";
  displayInOrder(root->right);
}

bool findnode(tree* root,tree* candidate,vector<int> &answer){
  if(root == nullptr) return false;
  if(root == candidate) return true;

  answer.push_back(0);
  if(findnode(root->left,candidate,answer)) return true;
  answer.pop_back(); answer.push_back(1);
  if(findnode(root->right,candidate,answer)) return true;
  answer.pop_back();
  return false;
}

// solution function
tree* lowestCommonAncestor(tree* root,tree* p,tree* q){
  vector<int> a,b; tree* temp = root;
  findnode(root,p,a); findnode(root,q,b);

  for(int i = 0;i < a.size() && i < b.size() && a[i] == b[i]; i++){
    if(a[i] == '0') temp = temp->left; else temp = temp->right;
  }
  return temp;
}

int main(){

  tree* root = nullptr;
  readLevelOrder(root);
  tree* t1; tree* t2;
  tree* answer = lowestCommonAncestor(root,t1,t2);
  cout<<answer->data<<endl;

  return 0;
}

// 4 3 7 2 5 6 9 -1 -1 -1 -1 -1 -1 -1 -1
