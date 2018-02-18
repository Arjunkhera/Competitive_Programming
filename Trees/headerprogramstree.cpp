#include "Tree.h"

int main(){

  tree* root = nullptr;
  // construct the tree preOrder way where leaves are -1
  // readTree(root);

  // construct tree using level order input where leaves have -1 as children
  readLevelOrder(root);

  // display the tree
  displayLevelorderRecursive(root);
  std::cout<<"\n--------------";
  std::cout<<countNodes(root)<<"\n------------";
  //std::cout<<getHeight(root)<<"\n-------------";
  std::pair<int,int> heightdia = getDiameterFast(root);
  std::cout<<heightdia.second<<"\n-------------";
  std::cout<<heightdia.first<<"\n-----------";

  return 0;
}

/*
1 2 3 -1 -1 4 5 -1 -1 -1 6 7 -1 -1 8 9 -1 11 -1 -1 10 12 -1 -1 -1
1 2 6 3 4 7 8 -1 -1 5 -1 -1 -1 9 10 -1 -1 -1 11 12 -1
*/
