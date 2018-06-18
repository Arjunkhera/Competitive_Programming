#include<iostream>
#include<stack>
#include<climits>

using namespace std;

class MinStack {
private:
  stack<int> main;
  stack<int> aux;

public:
    /** initialize your data structure here. */
    MinStack() { }

    void push(int x){
      main.push(x);
      if(aux.empty() || x <= aux.top()) aux.push(x);
    }

    void pop() {
      if(main.empty()) return;
      if(main.top() == aux.top()) aux.pop();
      main.pop();
    }

    int top() {
      return main.top();
    }

    int getMin() {
      return aux.top();
    }
};

int main(){

  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  cout<<minStack.getMin()<<endl;
  minStack.pop();
  cout<<minStack.top()<<endl;
  cout<<minStack.getMin()<<endl;
  return 0;
}
