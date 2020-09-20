// Leetcode question 23
// you can replace heap by std::priority_queue

#include<iostream>
#include<vector>
#include<queue>
#include<climits>

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

  while(x!=100){
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

// heap
void insertElement(std::vector<pair<int,int>> &heap,int data,int pos){

  // insert the data
  heap.push_back(make_pair(data,pos));
  int index = heap.size()-1;

  int parent = (index-1)/2;
  // balance the heap
  while( index > 0 && heap[parent].first > heap[index].first ){
    // swap the data
    heap[parent].swap(heap[index]);
    // cout<<"hello";
    index = parent;
    parent = (index-1)/2;
  }
}

void balanceHeap(std::vector<pair<int,int>> &heap,int index){

  int leftchild = 2*index+1;
  int rightchild = 2*index+2;
  int minimum = index;
  int heapSize = heap.size()-1;

  if(leftchild<= heapSize && heap[leftchild].first<heap[minimum].first)
    minimum = leftchild;
  if(rightchild<= heapSize && heap[rightchild].first<heap[minimum].first)
    minimum = rightchild;

  if(minimum != index){
    // swap the elements
    heap[index].swap(heap[minimum]);

    // balance the heap for subtree
    balanceHeap(heap,minimum);
  }
}

void removeMin(std::vector<pair<int,int>> &heap){

  // check if the heap is not empty
  if(heap.empty())
    return;

  int heapSize = heap.size()-1;
  heap[0] = heap[heapSize];
  heap.pop_back();

  // to maintain the minheap property
  balanceHeap(heap,0);
}

// this is similar to the third alternative in the solution set of leetcode
// solution function
node* mergeKLists(vector<node*>& lists){

  int k = lists.size();
  vector<pair<int,int>> heap;

  // construct the heap
  for(int i=0;i<k;i++){
    if(lists[i] == nullptr)
      continue;
    insertElement(heap,lists[i]->data,i);
  }

  // create a dummy node
  node* head = new node(-1);
  node* tail = head;
  node* temp;
  while(!heap.empty()){
    /*
    // debugging
    cout<<"-----------\n";
    for(int i=0;i<heap.size();i++)
      cout<<heap[i].first<<" ";
    cout<<"\n"  ;

    for(int i=0;i<lists.size();i++){
      display(lists[i]);
      cout<<"\n";
    }
    display(head);
    cout<<"\n";
    */

    temp = lists[heap[0].second];
    tail->next = temp;
    tail = temp;
    // move the head ahead
    temp = temp->next;
    // update the array of heads
    lists[heap[0].second] = temp;

    // detach the previous head of the list
    tail->next = nullptr;

    if(temp != nullptr){
        heap[0].first = temp->data;
        balanceHeap(heap,0);
    }
    else
      removeMin(heap);
  }

  // return the answer
  return head->next;
}

// using stl 
node* mergeKLists2(vector<node*>& lists){
  if(lists.empty()) return nullptr;

  // min heap of data and vector index
  auto cmp = [](pair<int,int> a,pair<int,int> b){ return a.first > b.first; };
  priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> heap(cmp);
  // construct the min heap
  for(int i = 0;i < lists.size();i++) if(lists[i] != nullptr) heap.emplace(lists[i]->data,i);

  pair<int,int> temp; int i;
  node* newhead = new node(0);
  node* answer = newhead;
  while(!heap.empty()){
    temp = heap.top(); heap.pop();
    i = temp.second;
    answer->next = lists[i]; answer = lists[i];
    lists[i] = lists[i]->next;
    if(lists[i] != nullptr) heap.emplace(lists[i]->data,i);
  }
  return newhead->next;
}

int main(){
  int k;
  cin>>k;

  vector<node*> lists(k);

  for(int i=0;i<k;i++){
    readList(lists[i]);
    //display(lists[i]);
    //cout<<"\n";
  }

  node* head = mergeKLists2(lists);
  display(head);
  cout<<"\n";
}

// sample input
/*
4
-6 -7 -8 100
-4 -4 -4 -6 -10 100
-6 -8 -8 -9 -10 100
0 -10 100
*/
