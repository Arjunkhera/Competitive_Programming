#include<iostream>
#include<queue>

using namespace std;

// linked list
struct node{
  int data;
  node* next;
  node(int dat):data(dat),next(nullptr){}
};

void insertAtHead(node* &head,int data){
  node* newNode = new node(data);
  newNode->next = head;
  head = newNode;
}

void readList(node* &head){
  int x;
  std::cin>>x;

  while(x!=-1){
    insertAtHead(head,x);
    std::cin>>x;
  }
}

void display(node* head){
  while(head != nullptr){
    std::cout<<head->data<<" ";
    head = head->next;
  }
}

// binary search tree
struct TreeNode{
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int dat):data(dat),left(nullptr),right(nullptr){}
};

void displayTree(TreeNode* root){

  if(root == nullptr)
    return;

  TreeNode* temp;
  queue<TreeNode*> levelorder;
  levelorder.push(root);
  levelorder.push(nullptr);

  while(1){
    temp = levelorder.front();
    levelorder.pop();

    if(temp == nullptr && levelorder.empty())
      break;

    if(temp == nullptr){
      cout<<"\n";
      levelorder.push(nullptr);
      continue;
    }
    cout<<temp->data<<" ";
    if(temp->left != nullptr)
      levelorder.push(temp->left);
    if(temp->right != nullptr)
      levelorder.push(temp->right);
  }
}

void inorder(TreeNode* root){
  if(root == nullptr)
    return;

  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

// solution function
TreeNode* sortedListToBST(node* head){
  // in case of empty list
  if(head == nullptr)
    return nullptr;

  // in case of a single element
  if(head->next == nullptr){
    TreeNode* root = new TreeNode(head->data);
    return root;
  }

  // find the midpoint
  node* prev = nullptr;
  node* slow = head;
  node* fast = head;

  while(fast != nullptr && fast->next != nullptr){
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  if(prev == nullptr)
    head = nullptr;
  else prev->next = nullptr;

  TreeNode* root = new TreeNode(slow->data);
  node* leftlist = head;
  node* rightlist = slow->next;

  root->left = sortedListToBST(leftlist);
  root->right = sortedListToBST(rightlist);

  return root;
}

int main(){

  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";
  TreeNode* root = sortedListToBST(head);

  displayTree(root);
  //inorder(root);
  cout<<"\n";

  return 0;
}

/*
input
9 5 0 -3 -10 -1
*/
