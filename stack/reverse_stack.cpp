#include<iostream>
#include "stack.h"

using namespace std;

void pushToBottom(stack &s,int n){
  if(s.isempty()){
    s.push(n);
    return;
  }

  int temp = s.top();
  s.pop();
  pushToBottom(s,n);
  s.push(temp);
}

void reverse(stack &s){
  if(s.isempty())
    return;

  int temp = s.top();
  s.pop();
  reverse(s);
  pushToBottom(s,temp);
}

int main(){
  stack s(15);

  s.push(1);
  s.push(2);
  s.push(3);
  int *ptr = s.begin();
  int n = s.size();

  cout<<"before\n";
  for(int i=0;i<n;i++)
    cout<<ptr[i]<<" ";
  cout<<"\n";
  reverse(s);

  cout<<"after\n";
  for(int i=0;i<n;i++)
    cout<<ptr[i]<<" ";
  cout<<"\n";
  return 0;
}
