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

tree* maketree(vector<int> &nums,int start,int end){
  if(start > end) return nullptr;
  if(start == end) return new tree(nums[start]);

  int mid = (start+end)/2;
  tree* root = new tree(nums[mid]);
  root->left = maketree(nums,start,mid-1);
  root->right = maketree(nums,mid+1,end);
  return root;
}

tree* sortedArrayToBST(vector<int>& nums){
  if(nums.empty()) return nullptr;
  return maketree(nums,0,nums.size()-1);
}

int main(){
  int temp;
  vector<int> arr;
  cin>>temp;
  while(temp != -1) { arr.push_back(temp); cin>>temp; }

  tree* root = sortedArrayToBST(arr);
  // displayLevelOrder(root);
  displayInOrder(root);
  cout<<endl;

  return 0;
}

// 5 4 8 11 -1 13 4 7 2 -1 -1 -1 1 -1 -1 -1 -1 -1 -1
