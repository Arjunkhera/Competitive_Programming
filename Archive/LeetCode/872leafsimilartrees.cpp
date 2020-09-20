#include <iostream>
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

// helper function
void inorder(TreeNode* root,vector<int> &answer){
  if(root == nullptr) return;

  if(root->left == nullptr && root->right == nullptr){
    answer.push_back(root->val);
    return;
  }
  inorder(root->left,answer);
  inorder(root->right,answer);
}

// solution function
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
  if(root1 == nullptr || root2 == nullptr)  return false;

  bool flag = true;
  vector<int> first,second;
  inorder(root1,first); inorder(root2,second);

  if(first.size() != second.size()) return false;
  for(int i = 0;i < first.size() && flag;i++) if(first[i] != second[i]) flag = false;
  return flag;
}

int main(){

  tree* root1 = nullptr;
  readLevelOrder(root1);

  tree* root2 = nullptr;
  readLevelOrder(root2);

  if(leafSimilar(root1,root2)) cout<<"Yes\n"; else cout<<"No\n";

  return 0;
}
