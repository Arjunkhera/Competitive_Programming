#include "heap.h"

int main(){
  std::vector<int> heap;

  insertElement(heap,3);
  insertElement(heap,2);
  deleteElement(heap,1);

  insertElement(heap,15);
  insertElement(heap,5);
  insertElement(heap,4);
  insertElement(heap,45);


  for(auto i:heap)
    std::cout<<i<<" ";
  std::cout<<"\n";


  std::cout<<removeMin(heap)<<" ";
  std::cout<<getMin(heap)<<" ";
  std::cout<<"\n" ;

  return 0;
}
