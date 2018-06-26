#ifndef __stack_H_INCLUDED__
#define __stack_H_INCLUDED__

class stack{
  int *stk;
  int capacity;
  int top_index;
  bool empty;

public:
  stack(int n=10):capacity(n),empty(true),top_index(-1){
    stk = new int[capacity];
  }
  bool push(int);
  bool pop();
  int top();
  bool isempty();
  int* begin();
  int* end();
  int size();
};

//void testing_simulation();

#endif
