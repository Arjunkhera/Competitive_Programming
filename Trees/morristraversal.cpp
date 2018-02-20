#include "Tree.h"
#include <stack>

// inorder traversal with stack : iterative version
void iterativeInorder(tree* root){

  if(root == nullptr)
    return;

  tree* cur = root;
  std::stack<tree*> nodes;
  bool flag = false;

  while(!flag){
    if(cur != nullptr)
      while(cur != nullptr){
        nodes.push(cur);
        cur = cur->left;
      }
    else
      if(nodes.empty())
        flag = true;
      else{
        cur = nodes.top();
        nodes.pop();
        std::cout<<cur->data<<" ";
        cur = cur->right;
      }
  }
}

// inorder traversal without stack -> constant space
void morristraversal(tree* root){

  if(root == nullptr)
    return;

  tree* current = root;
  tree* prev = nullptr;

  while(current != nullptr){

    if(current->left == nullptr){
      std::cout<<current->data<<" ";
      current = current->right;
      continue;
    }

    // find the inorder predecessor of current
    prev = current->left;
    while(prev->right != nullptr && prev->right != current)
      prev = prev->right;

    // check if already visited or not
    if(prev->right == nullptr){
      prev->right = current;
      current = current->left;
    }
    else {
      prev->right = nullptr;
      std::cout<<current->data<<" ";
      current = current->right;
    }
  }
}

int main(){
  tree* root;
  readLevelOrder(root);

  iterativeInorder(root);
  std::cout<<"\n";

  morristraversal(root);
  std::cout<<"\n";
}
