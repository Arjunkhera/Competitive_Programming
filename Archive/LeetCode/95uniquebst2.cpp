#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode* root){
  if(root == NULL)
    return;

  cout<<root->val;
  preOrder(root->left);
  preOrder(root->right);
}

vector<TreeNode*> solve(int start,int end){

  vector<TreeNode*> answer;

  if(start > end){
    answer.push_back(NULL);
    return answer;
  }

  for(int i = start; i <= end; i++){

    vector<TreeNode*> leftSubtree  = solve(start, i - 1);
    vector<TreeNode*> rightSubtree = solve(i + 1, end);

    for (int j = 0; j < leftSubtree.size(); j++){
      for(int k = 0; k < rightSubtree.size(); k++){

        TreeNode* node = new TreeNode(i);
        node->left = leftSubtree[j];
        node->right = rightSubtree[k];
        answer.push_back(node);
      }
    }
  }

  return answer;
}

// solution function
vector<TreeNode*> generateTreeNodes(int n){

  if(n == 0){
    vector<TreeNode*> answer {NULL};
    return answer;
  }

  return solve(1,n);
}

/*
vector<TreeNode*> generateTreeNodes_trydp_notworkingyet(int n) {

  vector<TreeNode*> answer;

  // base cases
  if(n == 0){
    answer.push_back(NULL);
    return answer;
  }

  arr[0].push_back(NULL);
  TreeNode* first = new TreeNode(1);
  arr[1].push_back(first);

  // bottom up dp
  for(int l = 2;l <= n; l++)
    for(int i = l;i >= 1;i--)
      for(int j = 0;j < arr[i-1].size();j++)
        for(int k = 0;k < arr[l-i].size();k++){
          TreeNode* temp = new TreeNode(i);
          temp->left = arr[i-1][j];
          temp->right = arr[l-i][k];

          if(i <= ceil(l/2)){
            //increment(temp->right);
          }
          arr[l].push_back(temp);
        }

  return arr[n];
}
*/

int main(){

  int n;
  cin>>n;

  vector<TreeNode*> answer = generateTreeNodes(n);
  cout<<"--------"<<endl;

  for(int i = 0;i < answer.size();i++){
    preOrder(answer[i]);
    cout<<endl;
  }

  return 0;
}
