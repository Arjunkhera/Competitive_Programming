#include "bstree.h"

int main(){

  node<int> *root;
  // take input for first tree
  root = input(root);

  // display inorder
  displayInorder(root);
  std::cout<<"\n";

  // level order print
  displayLevelorderIterative(root);
  std::cout<<"\n";

  // delete a node
  std::cout<<"deleting node 8\n";
  root = deleteNode(root,8);
  displayLevelorderIterative(root);
  std::cout<<"\n";

  // check if BST
  if(checkBST(root))
    std::cout<<"The given tree is BST\n";
  else std::cout<<"The given tree is not BST";

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

  // create a mirror image of the tree
  generateMirror(root);
  displayInorder(root);
  //std::cout<<"\n";

  // level order print
  //displayLevelorderIterative(root);
  displayLevelorderRecursive(root);
  std::cout<<"\n";

  std::cout<<"-------------\n";

  // constructing second tree
  node<int> *root_second;

  return 0;
}
