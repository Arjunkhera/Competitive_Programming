#include "Tree.h"

bool isIdentical(tree* first,tree* second){

  // base case
  if(first == nullptr && second == nullptr)
    return true;

  if(first != nullptr && second != nullptr)
    if(first->data == second->data && isIdentical(first->left,second->left) && isIdentical(first->right,second->right))
      return true;

  return false;    
}

int main(){

  tree* first;
  readLevelOrder(first);

  tree* second;
  readLevelOrder(second);

  if(isIdentical(first,second))
    std::cout<<"Trees are identical \n";
  else std::cout<<"Trees are not identical \n";

  return 0;
}
