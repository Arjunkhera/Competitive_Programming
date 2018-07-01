bool search(TreeNode* root,TreeNode* target,string path,string cur){
  if(root == nullptr) return false;
  if(root == target) { path = cur; return true; }

  if(search(root->left,target,path,cur+"0")) return true;
  return search(root->right,target,path,cur+"1");
}

void findnodes(TreeNode* root,TreeNode* target, int K,int cur,int i,string path,vector<int> &answer){
  if(root == nullptr) return; if(root == target) return;

  if(cur >= K){
    if(cur == K) answer.push_back(root->val);
    if(path[i] == '0') findnodes(root->left,target,K,cur-1,i+1,path,answer);
    else findnodes(root->right,target,K,cur-1,i+1,path,answer);
    return;
  }

  if(path[i] == '0'){
    findnodes(root->left,target,K,cur-1,i+1,path,answer);
    findnodes(root->right,target,K,cur+1,i+1,path,answer);
  }
  else {
    findnodes(root->right,target,K,cur-1,i+1,path,answer);
    findnodes(root->left,target,K,cur+1,i+1,path,answer);
  }
}

void findchildnodes(TreeNode* root,int cur,int K,vector<int> &answer){
  if(root == nullptr) return;
  if(cur == K) { answer.push_back(root->val); return; }

  findchildnodes(root->left,cur+1,K,answer);
  findchildnodes(root->right,cur+1,K,answer);
}

vector<int> distanceK(TreeNode* root,TreeNode* target, int K){
  vector<int> answer;
  if(root == nullptr || target == nullptr) return false;
  string path; search(root,target,path,"");
  findnodes(root,target,K,path.length(),0,path,answer);
  findchildnodes(target,0,K,answer);
  return answer;
}
