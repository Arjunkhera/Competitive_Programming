#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node{
  int data;
  node* left; node*right;
  node(int dat):data(dat),left(nullptr),right(nullptr){}
};

// using priority queues for user defined types : method 1
void priorityuser(){
  // here we use lambda function to make a comparator
  auto cmp = [](struct node* a,struct node *b){return a->data > b->data;};
  priority_queue<struct node*,vector<struct node*>,decltype(cmp)> heap(cmp);

}

// comparator for method 2
class compare{
  public:
    bool operator()(pair<int,int> &a,pair<int,int> &b){
      return a.second > b.second;
    }
};

// using priority queues for user defined types : method 2
void priorityuser2(){
  // pair is used for ease of demonstration, you can use your object also
  // compare has to be always a class
  priority_queue<pair<int,int>,vector<pair<int,int>>,compare> help;
  help.emplace(7,21);
  help.emplace(9,25);
  help.emplace(1,29);
  help.emplace(6,30);

  while(!help.empty()){
    cout<<help.top().first<<" : "<<help.top().second<<endl;
    help.pop();
  }
}

// using priority queues for inbuilt data types : by default max heap
void priority(){
  // for min heap
  // priority_queue<int,vector<int>,greater<int>> minheap;

  // construct a max heap
  priority_queue<int> hp;
  // pushing
  for(int i = 1;i < 5;i++) hp.push(i);

  // size of the heap
  cout<<hp.size()<<endl;

  // removing elements
  while(!hp.empty()) { cout<<hp.top()<<" "; hp.pop(); }
  cout<<"\n";
}

int main(){
  priority();
  priorityuser();
  priorityuser2();
  return 0;
}
