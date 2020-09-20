#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class test{
public:
  void print();
};

inline void test::print(){
  cout<<"Inside the object\n";
}

int main() {

  test t;
  t.print();

	return 0;
}
