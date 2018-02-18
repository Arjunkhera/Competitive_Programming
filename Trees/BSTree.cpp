#include<iostream>
#include<queue>
#include<iomanip>

struct tree{
  int data;
  tree* left;
  tree* right;
  tree(int dat):data(dat),left(nullptr),right(nullptr){}
};

int getHeight(tree*);

tree* insertNode(tree* root,tree* newNode){

  // base case
  if(root == nullptr)
    return newNode;

  if(root->data >= newNode->data)
    root->left = insertNode(root->left,newNode);
  else root->right = insertNode(root->right,newNode);

  return root;
}

void readTree(tree* &root){
  int dat;
  std::cin>>dat;

  while(dat != -1){
    tree* newNode = new tree(dat);
    root = insertNode(root,newNode);
    std::cin>>dat;
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

void displayPreOrder(tree* root){
  if(root == nullptr)
    return;

  std::cout<<root->data<<" ";
  displayPreOrder(root->left);
  displayPreOrder(root->right);
}

void displayPostOrder(tree* root){
  if(root == nullptr)
    return;

  displayPostOrder(root->left);
  displayPostOrder(root->right);
  std::cout<<root->data<<" ";
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

void displayKthLevel(tree *root,int displaylevel,int curlevel){
  if(root == nullptr)
    return;

  if(curlevel == displaylevel)
    std::cout<<root->data<<" ";

  displayKthLevel(root->left,displaylevel,curlevel+1);
  displayKthLevel(root->right,displaylevel,curlevel+1);
}

void displayLevelorderRecursive(tree *root){
  int maxLevel = getHeight(root);

  for(int i=0;i<=maxLevel;i++){
    displayKthLevel(root,i,0);
    std::cout<<"\n";
  }
}

// display in proper tree format
void displayBeautiful(tree* root){
  if(root == nullptr)
    return;

  tree* temp;

  temp = root->left;
  int space = 0,dist;
  while(temp != nullptr){
    space++;
    temp = temp->left;
  }

  std::queue<std::pair<tree*,int>> nodes;
  nodes.push(std::make_pair(root,space));
  nodes.push(std::make_pair(nullptr,0));

  while(1){
    temp = nodes.front().first;
    space = nodes.front().second;
    nodes.pop();

    if(temp == nullptr && nodes.empty())
      break;
    if(temp == nullptr){
      std::cout<<"\n";
      nodes.push(std::make_pair(nullptr,0));
      continue;
    }

    dist = space;
    while(dist--)
      std::cout<<" ";
    std::cout<<temp->data<<" ";
    if(temp->left != nullptr)
      nodes.push(std::make_pair(temp->left,space-1));
    if(temp->right != nullptr)
      nodes.push(std::make_pair(temp->right,space+1));
  }
}

int countNodes(tree* root){

  // base case
  if(root == nullptr)
    return 0;

  return 1+countNodes(root->left)+countNodes(root->right);
}

int getHeight(tree* root){

  // base case : empty leaf
  if(root == nullptr)
    return -1;

  // base case : reaching a leaf node
  if(root->left == nullptr && root->right == nullptr)
    return 0;

  int leftHeight = 1+getHeight(root->left);
  int rightHeight = 1+getHeight(root->right);

  return std::max(leftHeight,rightHeight);
}

int getDepth(tree* root,tree* cur){

}

int getDiameter(tree* root){

  // base case : empty leaf
  if(root == nullptr)
    return 0;

  // base case : reaching a leaf node
  if(root->left == nullptr && root->right == nullptr)
    return 0;

  int leftDiameter = getDiameter(root->left);
  int rightDiameter = getDiameter(root->right);
  int leftHeight = 1+getHeight(root->left);
  int rightHeight = 1+getHeight(root->right);
  int currentDiameter = leftHeight+rightHeight;

  return std::max(currentDiameter,std::max(leftDiameter,rightDiameter));
}

std::pair<int,int> getDiameterFast(tree* root){

  // base case : empty leaf
  if(root == nullptr)
    return std::make_pair(0,-1);

  // base case : reaching a leaf node
  if(root->left == nullptr && root->right == nullptr)
    return std::make_pair(0,0);


  std::pair<int,int> left = getDiameterFast(root->left);
  std::pair<int,int> right = getDiameterFast(root->right);
  int leftHeight = 1+left.second;
  int rightHeight = 1+right.second;
  int currentHeight = std::max(leftHeight,rightHeight);
  int currentDiameter = std::max(leftHeight+rightHeight,std::max(left.first,right.first));

  return std::make_pair(currentDiameter,currentHeight);
}

int main(){

  // never forget to initialize root to nullptr, otherwise the program would not work
  tree* root = nullptr;
  readTree(root);

  displayLevelOrder(root);
  std::cout<<"\n";

  return 0;
}
