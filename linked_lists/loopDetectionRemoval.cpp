#include "LinkedList.h"
#include<unordered_set>

using namespace std;

// using hash table of visited nodes
bool detectLoopHash(node *head){
  unordered_set<node*> visited;

  // assuming there is no loop
  bool flag = false;
  while(head != nullptr){
    if(visited.find(head) != visited.end()){
      // make true and exit as we found loop
      flag = true;
      break;
    }
    visited.insert(head);
    head = head->next;
  }

  return flag;
}

void removeLoopHash(node *head){
  unordered_set<node*> visited;

  visited.insert(head);
  visited.insert(head->next);
  node* temp = head->next;

  while(true){
    if(visited.find(temp->next) != visited.end())
      break;
    visited.insert(temp);
    temp = temp->next;
  }

  temp->next = nullptr;
}

// floyds cycle finding algorithm
bool detectLoop(node* &head){
  if(head == nullptr)
    return false;

  node* slow = head;
  node* fast = head;

  bool flag = false;
  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){
      flag = true;
      break;
    }
  }

  return flag;
}

void removeLoop(node* &head){

  node* slow = head;
  node* fast = head;

  // first find the intersection point
  do{
    slow = slow->next;
    fast = fast->next->next;
  }while(slow != fast);

  // remove the loop
  // check out gfg for explanation, can be derived using good old linear algebra
  slow = head;
  while(slow->next != fast->next){
      slow = slow->next;
      fast = fast->next;
  }
  if(slow == fast){
    head = slow->next;
    slow->next = nullptr;
  }
  else fast->next = nullptr;
}

// helper for makeLoop
node* findMidpoint(node* head){
  if(head == nullptr)
    return nullptr;

  node* mid = nullptr;
  node* slow = head;
  node* fast = head;

  while(fast->next != nullptr && fast->next->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

// for testing purposes : we need to make a loop :)
void makeLoop(node* head){
  node* tail = head;
  node* mid = findMidpoint(head);
  while(tail->next != nullptr)
    tail = tail->next;

  tail->next = mid;
}

int main(){

  node* head = nullptr;
  readList(head);

  // for testing purpose
  makeLoop(head);

  if(detectLoopHash(head)){
    cout<<"Loop detected in the list\n";
    removeLoopHash(head);
    cout<<"Loop removed\n";
  }
  else cout<<"No loop present in the list\n";

  display(head);
  cout<<"\n";

  return 0;
}
