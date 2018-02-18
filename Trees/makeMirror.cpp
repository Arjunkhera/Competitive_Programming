#include "Tree.h"

void makeMirror(tree* &root){
  // base case
  if(root == nullptr)
    return;

  std::swap(root->left,root->right);

  // make recursive calls
  makeMirror(root->left);
  makeMirror(root->right);
}

int main(){

  tree* root;
  readLevelOrder(root);

  std::cout<<"Original tree : \n";
  displayLevelOrder(root);

  makeMirror(root);

  std::cout<<"Mirror tree : \n";
  displayLevelOrder(root);

  return 0;
}
