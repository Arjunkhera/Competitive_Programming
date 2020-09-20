#include <iostream>
#include <queue>
#include <climits>

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

// helper function for brute force
void finddepth(tree* root,int curdepth,int &maxdepth,string str,vector<string> &arr){
  if(root == nullptr) return;
  if(root->left == nullptr && root->right == nullptr && curdepth >= maxdepth){
    if(curdepth > maxdepth) { maxdepth = curdepth; arr.clear(); }
    arr.push_back(str);
    return;
  }

  finddepth(root->left,curdepth+1,maxdepth,str+"0",arr);
  finddepth(root->right,curdepth+1,maxdepth,str+"1",arr);
}

// solution using bruteforce
tree* subtreeWithAllDeepestbrute(tree* root){
  if(root == nullptr) return nullptr;

  vector<string> arr; int maxdepth = 0;
  finddepth(root,0,maxdepth,"",arr);

  int i,j;
  for(i = 0;i < arr[0].size();i++){
    for(j = 1;j < arr.size();j++) if(arr[j][i] != arr[j-1][i]) break;
    if(j != arr.size()) break;
  }

  tree* answer = root;
  for(int k = 0;k < i;k++)
    if(arr[0][k] == '0') answer = answer->left; else answer = answer->right;
  return answer;
}

// helper function : do dfs and construct answer bottom up
pair<tree*,int> dfs(tree* root){
  if(root == nullptr) return make_pair(nullptr,0);

  pair<tree*,int> left = dfs(root->left);
  pair<tree*,int> right = dfs(root->right);

  if(left.second > right.second) { left.second++; return left;}
  if(right.second > left.second) { right.second++; return right;}
  return make_pair(root,1+left.second);
}

// solution function : fastest
tree* subtreeWithAllDeepest(tree* root){
  if(root == nullptr) return nullptr;

  pair<tree*,int> answer = dfs(root);
  return answer.first;
}

// driver function
int main(){

  tree* root;
  readLevelOrder(root);

  tree* answer = subtreeWithAllDeepest(root);
  displayLevelOrder(answer);
  cout<<endl;

  return 0;
}

/*
3 5 1 6 2 0 8 -1 -1 7 4 -1 -1 -1 -1 -1 -1 -1 -1
*/
