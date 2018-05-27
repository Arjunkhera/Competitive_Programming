#include<iostream>
#include<vector>
#include<typeinfo>

using namespace std;

void learningAuto(){

  vector<int> arr(5,5);

  for(auto i:arr)
    cout<<i<<" ";

  cout<<endl;
}

void learningDecltype(){

  int a = 12;
  decltype(a) x;

  cout<<typeid(x).name()<<endl;
}

int main(){

  learningAuto();
  learningDecltype();

  return 0;
}
