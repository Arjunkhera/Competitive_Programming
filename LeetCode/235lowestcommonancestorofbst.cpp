bool findnode(tree* root,tree* candidate,string answer,string cur){
  if(root == nullptr) return false;
  if(root == candidate) { answer = cur; return true; }

  if(findnode(root->left,candidate,answer,cur+"0")) return true;
  return findnode(root->right,candidate,answer,cur+"1") return false;
}

// solution function
tree* lowestCommonAncestor(tree* root,tree* p,tree* q){
  string a,b; tree* temp = root;
  findnode(root,p,a,""); findnode(root,q,b,"");

  for(int i = 0;i < a.size() && i < b.size() && a[i] == b[i]; i++){
    if(a[i] == '0') temp = temp->left; else temp = temp->right;
  }
  return temp;
}
