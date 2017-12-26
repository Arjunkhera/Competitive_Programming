#include "tree.h"

int main(){

  node<int> *root;
  // take input for first tree
  root = input(root);

  // display inorder
  displayInorder(root);
  std::cout<<"\n";

  // getHeight
  std::cout<<"Height is: "<<getHeight(root)<<"\n";

  // getDiameter
  std::cout<<"Diameter is: "<<getDiameter(root)<<"\n";

  // getDiameterFast
  std::pair<int,int> answer = getDiameterFast(root);
  std::cout<<"Fast Height is: "<<answer.second<<"\n";
  std::cout<<"Fast Diameter is: "<<answer.first<<"\n";

  // create a mirror image of the tree
  //generateMirror(root);
  //displayInorder(root);
  //std::cout<<"\n";

  // level order print
  displayLevelorderIterative(root);
  std::cout<<"\n";

  std::cout<<"-------------\n";

  // constructing second tree
  node<int> *root_second;

  // level order input
  root_second = inputLevelOrder(root_second);

  // level order print second tree
  displayLevelorderIterative(root_second);
  std::cout<<"\n";

  // to compare if two tree are same
  if(identicalTrees(root,root_second))
    std::cout<<"The trees are same \n";
  else std::cout<<"The trees are different\n";

  return 0;
}
