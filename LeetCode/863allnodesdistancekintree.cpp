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

bool search(tree* root,tree* target,string path,string cur){
  if(root == nullptr) return false;
  if(root == target) { path = cur; return true; }

  if(search(root->left,target,path,cur+"0")) return true;
  return search(root->right,target,path,cur+"1");
}

void findchildnodes(tree* root,int cur,int K,vector<int> &answer){
  if(root == nullptr) return;
  if(cur == K) { answer.push_back(root->data); return; }

  findchildnodes(root->left,cur+1,K,answer);
  findchildnodes(root->right,cur+1,K,answer);
}

void findnodes(tree* root,tree* target, int K,int cur,int i,string path,vector<int> &answer){
  if(root == nullptr) return; if(root == target) return;

  if(cur >= K){
    if(cur == K) answer.push_back(root->data);
    if(path[i] == '0') findnodes(root->left,target,K,cur-1,i+1,path,answer);
    else findnodes(root->right,target,K,cur-1,i+1,path,answer);
    return;
  }

  if(path[i] == '0'){
    findnodes(root->left,target,K,cur-1,i+1,path,answer);
    findchildnodes(root->right,cur+1,K,answer);
  }
  else {
    findnodes(root->right,target,K,cur-1,i+1,path,answer);
    findchildnodes(root->left,cur+1,K,answer);
  }
}

vector<int> distanceK(tree* root,tree* target, int K){
  vector<int> answer;
  if(root == nullptr || target == nullptr) return answer;
  string path; search(root,target,path,"");
  findnodes(root,target,K,path.length(),0,path,answer);
  findchildnodes(target,0,K,answer);
  return answer;
}

int main(){

  tree* root;
  readLevelOrder(root);
  tree* target;
  readLevelOrder(target);
  int n; cin>>n;

  // displayLevelOrder(root);
  vector<int> answer = distanceK(root,target,n);
  for(auto i:answer) cout<<i<<" "; cout<<endl;
  return 0;
}

// 3 5 1 6 2 0 8
