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

// helper function
void inorderforkth(tree* root,int k,int &curpos,int &answer){
  if(root == nullptr) return;
  if(k == curpos) return;

  inorderforkth(root->left,k,curpos,answer);
  curpos++; if(k == curpos) { answer = root->data; return; }
  inorderforkth(root->right,k,curpos,answer);
}

// solution function
int kthSmallest(tree* root,int k) {
  if(root == nullptr) return 0;
  int curpos = 0,answer = 0;

  inorderforkth(root,k,curpos,answer);
  return answer;
}

// driver function
int main(){

  tree* root;
  readLevelOrder(root);

  int k; cin>>k;

  cout<<kthSmallest(root,k)<<endl;
  return 0;
}

/*
3 5 1 6 2 0 8 -1 -1 7 4 -1 -1 -1 -1 -1 -1 -1 -1
*/
