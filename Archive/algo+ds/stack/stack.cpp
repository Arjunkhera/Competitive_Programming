#include "stack.h"

bool stack::push(int n){
  // stackoverflow
  if(this->top_index+1 == this->capacity)
    return false;

  // pushing an element
  stk[++this->top_index] = n;
  // if the first element is being pushed
  if(this->top_index >= 0)
    this->empty = false;
  return true;
}

bool stack::pop(){
  // empty stack
  if(this->empty)
    return false;

  // pop an element
  this->top_index--;
  // check if stack is empty
  if(this->top_index < 0)
    this->empty = true;
  return true;
}

int stack::top(){
  if(this->empty)
    return -1;

  return stk[this->top_index];
}

bool stack::isempty(){
  return this->empty;
}

int* stack::begin(){
  if(this->empty)
    return nullptr;

  return stk;
}

int* stack::end(){
  if(this->empty)
    return nullptr;

  return stk+this->top_index;
}

int stack::size(){
  if(isempty())
    return 0;

  return top_index+1;
}

/*
void testing(){
  stack s(15);

  s.push(1);
  s.push(3);
  s.push(5);
  s.push(7);
  s.push(8);
  //display(s);
  std::cout<<s.top()<<std::endl;    // 8
  s.pop(); // pop 8
  s.pop(); // pop 7
  s.pop(); // pop 5
  std::cout<<s.top()<<std::endl; // 3
  s.pop(); // pop 3
  s.pop(); // pop 1
  std::cout<<s.top()<<std::endl; // -1
  std::cout<<s.isempty()<<std::endl; // empty-->1
}
*/
