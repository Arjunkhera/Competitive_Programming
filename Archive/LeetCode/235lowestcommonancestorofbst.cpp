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

// solution function
tree* lowestCommonAncestor(tree* root,tree* p,tree* q){
   if(root == nullptr) return nullptr;

   if((root->data >= p->data && root->data <= q->data)||(root->data <= p->data && root->data >= q->data)) return root;

   if(root->data > p->data) return lowestCommonAncestor(root->left,p,q);
   return lowestCommonAncestor(root->right,p,q);
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
