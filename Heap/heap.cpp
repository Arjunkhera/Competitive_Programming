#include "heap.h"

int getMin(std::vector<int> &heap){

  // check if the heap is not empty
  if(heap.empty())
    return INT_MAX;

  return heap[0];
}

void balanceHeap(std::vector<int> &heap,int index){

  int leftchild = 2*index+1;
  int rightchild = 2*index+2;
  int minimum = index;
  int heapSize = heap.size()-1;

  if(leftchild<= heapSize && heap[leftchild]<heap[minimum])
    minimum = leftchild;
  if(rightchild<= heapSize && heap[rightchild]<heap[minimum])
    minimum = rightchild;

  if(minimum != index){
    // swap the elements
    int temp = heap[index];
    heap[index] = heap[minimum];
    heap[minimum] = temp;

    // balance the heap for subtree
    balanceHeap(heap,minimum);
  }
}

int removeMin(std::vector<int> &heap){

  // check if the heap is not empty
  if(heap.empty())
    return INT_MAX;

  int minimum = heap[0];
  int heapSize = heap.size()-1;
  heap[0] = heap[heapSize];
  heap.pop_back();
  // to maintain the minheap property
  balanceHeap(heap,0);

  return minimum;
}

void insertElement(std::vector<int> &heap,int data){

  // insert the data
  heap.push_back(data);
  int index = heap.size()-1;

  int parent = (index-1)/2;
  // balance the heap
  while( index > 0 && heap[parent] > heap[index] ){
    // swap the data
    int temp = heap[parent];
    heap[parent] = heap[index];
    heap[index] = temp;

    index = parent;
    parent = (index-1)/2;
  }
}

bool deleteElement(std::vector<int> &heap,int index){

  int heapSize = heap.size()-1;

  // check if the heap is empty
  if(heapSize == -1)
    return false;

  // if the index is out of range
  if(index > heapSize || index < 0)
    return false;

  // bubble this index to the root
  heap[index] = INT_MIN;
  int parent = (index-1)/2;
  // balance the heap
  while( index > 0 ){
    // swap the data
    int temp = heap[parent];
    heap[parent] = heap[index];
    heap[index] = temp;

    index = parent;
    parent = (index-1)/2;
  }

  // remove this new root element
  removeMin(heap);
}
