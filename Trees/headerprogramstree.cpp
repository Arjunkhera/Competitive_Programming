#include "Tree.h"

int main(){

  tree* root = nullptr;
  // construct the tree preOrder way where leaves are -1
  // readTree(root);

  // construct tree using level order input where leaves have -1 as children
  readLevelOrder(root);

  // display the tree
  displayLevelorderRecursive(root);

  // number of nodes
  std::cout<<"Number of nodes are: "<<countNodes(root)<<"\n";

  // getHeight
  std::cout<<"Height is: "<<getHeight(root)<<"\n";

  // getDiameter
  std::cout<<"Diameter is: "<<getDiameter(root)<<"\n";

  // getDiameterFast
  std::pair<int,int> answer = getDiameterFast(root);
  std::cout<<"Fast Height is: "<<answer.second<<"\n";
  std::cout<<"Fast Diameter is: "<<answer.first<<"\n";

  return 0;
}

/*
1 2 3 -1 -1 4 5 -1 -1 -1 6 7 -1 -1 8 9 -1 11 -1 -1 10 12 -1 -1 -1
1 2 6 3 4 7 8 -1 -1 5 -1 -1 -1 9 10 -1 -1 -1 11 12 -1
*/
