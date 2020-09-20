#include<iostream>

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

node* findMidpoint(node* head){

  if(head == nullptr || head->next == nullptr)
    return head;

  node* slow = head;
  node* fast = head;

  while(fast->next != nullptr && fast->next->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

node* merge(node* leftlist,node* rightlist){
  node* head = new node(-1);
  node* tail = head;

  while(leftlist != nullptr && rightlist != nullptr)
    if(leftlist->data < rightlist->data){
      tail->next = leftlist;
      tail = leftlist;
      leftlist = leftlist->next;
      tail->next = nullptr;
    }
    else{
      tail->next = rightlist;
      tail = rightlist;
      rightlist = rightlist->next;
      tail->next = nullptr;
    }

  if(leftlist != nullptr)
    tail->next = leftlist;
  if(rightlist != nullptr)
    tail->next = rightlist;

  return head->next;
}

// solution function
node* sortList(node* head){

  if(head == nullptr || head->next == nullptr)
    return head;

  node* mid = findMidpoint(head);

  node* leftlist = head;
  node* rightlist = mid->next;
  mid->next = nullptr;

  leftlist = sortList(leftlist);
  rightlist = sortList(rightlist);
  return merge(leftlist,rightlist);
}

// for iterative version
node* merge(node* left,node* right,node* head){
    node *tail = head;

    while(left != nullptr && right != nullptr)
        if(left->data < right->data){
            tail = tail->next = left;
            left = left->next;
        }
        else{
            tail = tail->next = right;
            right = right->next;
        }
    tail->next = (left?left:right);
    while(tail->next) tail = tail->next;
    return tail;
}

node* split(node *head,int n){
    for(int i = 1; head && i < n;i++) head = head->next;

    if(!head) return nullptr;
    node *otherhalf = head->next;
    head->next = nullptr;
    return otherhalf;
}

// iterative version
node* sortListiterative(node* head){
    if(head == nullptr || head->next == nullptr) return head;

    int length = 0;
    node *temp = head;
    while(temp) { length++; temp = temp->next; }

    node dummy(-1); dummy.next = head;
    node *left,*right,*tail,*cur;

    for(int i = 1;i < length; i <<= 1){
        cur = dummy.next;
        tail = &dummy;
        while(cur){
            left = cur;
            right = split(cur,i);
            cur = split(right,i);
            tail = merge(left,right,tail);
        }
    }
    return dummy.next;
}

int main(){

  node* head = nullptr;
  readList(head);
  display(head);
  cout<<"\n";

  head = sortList(head);

  display(head);
  cout<<"\n";

  return 0;
}

/*
input
3 9 10 2 1 8 3 4 -1
*/
