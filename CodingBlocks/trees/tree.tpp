template<typename t>
node<t>* input(node<t> *root){
  int dat;
  std::cin>>dat;

  if(dat == -1)
    return nullptr;

  root = new node<t>(dat);
  root->left = input(root->left);
  root->right = input(root->right);

  return root;
}

template<typename t>
node<t>* inputLevelOrder(node<t> *root){

}

template<typename t>
void displayPostorder(node<t> *root){
  if(root == nullptr)
    return;

  displayPostorder(root->left);
  displayPostorder(root->right);
  std::cout<<root->data<<" ";
}

template<typename t>
void displayPreorder(node<t> *root){
  if(root == nullptr)
    return;

  std::cout<<root->data<<" ";
  displayPreorder(root->left);
  displayPreorder(root->right);
}

template<typename t>
void displayInorder(node<t> *root){

  if(root == nullptr)
    return;

  displayInorder(root->left);
  std::cout<<root->data<<" ";
  displayInorder(root->right);
}

void displayLevelorderIterative(){};
void displayLevelorderRecursive(){};

template<typename t>
t getHeight(node<t> *root){
  if(root == nullptr)
    return 0;

  t left_height = getHeight(root->left)+1;
  t right_height = getHeight(root->right)+1;
  if( left_height > right_height )
    return left_height;
  else return right_height;
}

template<typename t>
t getDiameter(node<t> *root){}

void test_header(){
  std::cout<<"Hello world\n";
}
