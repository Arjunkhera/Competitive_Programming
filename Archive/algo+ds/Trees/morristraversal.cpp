#include "Tree.h"
#include <stack>

// inorder traversal with stack : iterative version
void iterativeInorder(tree* root){

  if(root == nullptr) return;
  tree* cur = root; std::stack<tree*> nodes;

  while(cur && !nodes.empty()){
    if(cur != nullptr)
      while(cur != nullptr){ nodes.push(cur); cur = cur->left; }
    else{ cur = nodes.top(); nodes.pop();
          std::cout<<cur->data<<" "; cur = cur->right;
    }
  }
}

// inorder traversal without stack -> constant space
void morristraversal(tree* root){

  if(root == nullptr) return;

  tree* current = root,prev = nullptr;

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

void preOrderIterative(tree* root){

  if(root == nullptr)
    return;

  std::stack<tree*> stk;
  tree* cur = root;
  bool flag = true;

  while(flag){
      if(cur != nullptr){
        std::cout<<cur->data<<" ";
        stk.push(cur->right);
        cur = cur->left;
        continue;
      }

      if(stk.empty()){
        flag = false;
        continue;
      }

      cur = stk.top();
      stk.pop();
  }

}

void preOrderMorris(tree* root){

  if(root == nullptr)
    return;

  tree* cur = root;
  tree* prev = nullptr;

  while(cur != nullptr){

    if(cur->left == nullptr){
      std::cout<<cur->data<<" ";
      cur = cur->right;
      continue;
    }

    prev = cur->left;
    while( prev->right != nullptr && prev->right != cur )
      prev = prev->right;

    // visiting current for the first time
    if(prev->right == nullptr){
      std::cout<<cur->data<<" ";
      prev->right = cur;
      cur = cur->left;
      continue;
    }

    // visiting current first second time
    prev->right = nullptr;
    cur = cur->right;
  }

}

void postOrderIterativeTwoStack(tree * root){

  tree node* cur;
  stack<tree*> processed;
  stack<tree*> inq;

  while(!processed.empty()){

    cur = processed.top();
    processed.pop();



  }
}

void postOrderIterativeSingleStack(tree * root){

}

int main(){
  tree* root;
  readLevelOrder(root);

  //iterativeInorder(root);
  std::cout<<"\n";

  //morristraversal(root);
  std::cout<<"\n";

  preOrderIterative(root);
  std::cout<<"\n";

  preOrderMorris(root);
  std::cout<<"\n";
}
